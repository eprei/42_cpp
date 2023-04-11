#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if (this != &rhs)
		this->_csvMap = rhs._csvMap;
	return *this;
}

bool	BitcoinExchange::startExchange( char **argv )
{
	if ( openFiles( argv ) == false )
		return false;
	return true;
}

void	resetVariables(std::string &line, std::string &keyStr, std::string &valueStr, float &valueFloat)
{
	line.clear();
	keyStr.clear();
	valueStr.clear();
	valueFloat = 0;
}

bool	BitcoinExchange::openFiles( char **argv)
{
	std::string line;
	std::string keyStr;
	std::string	valueStr;
	float		valueFloat;

	_hisroticCsvFile.open("data.csv");
	if ( _hisroticCsvFile.is_open() == false )
		return printError(1, " ");
	_userInputFile.open(argv[1]);
	if ( _userInputFile.is_open() == false )
	{
		_hisroticCsvFile.close();
		return printError(2, argv[1]);
	}
	while (std::getline(_hisroticCsvFile, line))
	{
		std::stringstream ss(line);

		std::getline(ss, keyStr, ',');
		std::getline(ss, valueStr, ',');
		valueFloat = std::atof(valueStr.c_str());
		_csvMap[keyStr] = valueFloat;
		keyStr.clear();
		valueStr.clear();
	}
	_hisroticCsvFile.close();
	resetVariables(line, keyStr, valueStr, valueFloat);
	while (std::getline(_userInputFile, line))
	{
		std::stringstream ss(line);

		std::getline(ss, keyStr, '|');
		std::getline(ss, valueStr, '|');
		if (keyStr.length() > 10 && keyStr.at(10) == ' ')
			keyStr.erase(keyStr.length() - 1);
		if (keyStr != "date ")
		{
			valueFloat = std::atof(valueStr.c_str());
			printResults(keyStr, valueFloat);
		}
		keyStr.clear();
		valueStr.clear();
	}
	_userInputFile.close();
	return true;
}

bool	BitcoinExchange::printError( int i, const std::string &str) const
{
	if (i == 1)
		std::cerr << "Error: data.csv could not be opened" << std::endl;
	else if ( i == 2)
		std::cerr << "Error: " << str << " could not be opened" << std::endl;
	return false;
}

void	BitcoinExchange::printResults( std::string &key, float &value )
{
	if ( validInput( key, value ) == false)
		return;
	std::map<std::string, float>::iterator itup = _csvMap.upper_bound(key);
	if (itup != _csvMap.begin())
		itup--;
	std::cout << key << " => " << value << " = " << value * itup->second << std::endl;
}

bool	BitcoinExchange::validInput(std::string &key, float &value){
	if ( validDate( key ) == false)
	{
		std::cerr << "Error: bad input => " << key << std::endl;
		return false;
	}
	else if ( value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	else if ( value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::validDate(const std::string &str)
{
	std::string	date = str;
	std::string	delimiter = "-";
	std::string	extract;
	size_t		pos = 0;
	int			year, month, day;

	if (checkChars(date) == false)
		return false;
	for (int i = 0; i < 3; i++)
	{
		pos = date.find(delimiter);
		extract = date.substr(0, pos);
		if (i == 0)
			year = std::atoi(extract.c_str());
		if (i == 1)
			month = std::atoi(extract.c_str());
		if (i == 2)
			day = std::atoi(extract.c_str());
		date.erase(0, pos + delimiter.length());
	}
	if ( !( 1970 <= year && year <= 2023 ) || !( 1 <= month && month <= 12) || !( 1 <= day && day <= 31))
		return false;
	return true;
}

bool	BitcoinExchange::checkChars(std::string date)
{
	const char	*validChars = "0123456789-";

	for (size_t i = 0; i < date.size(); i++)
	{
		if (strchr(validChars, date.at(i)) == NULL)
			return false;
	}
	if (date.length() != 10 || date.at(4) != '-' || date.at(7) != '-')
		return false;
	return true;
}
