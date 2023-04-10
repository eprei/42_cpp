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
	printResults();
	return true;
}

void	resetVariables(std::string &line, std::string &keyStr, std::string &valueStr, double &valueDouble)
{
	line.clear();
	keyStr.clear();
	valueStr.clear();
	valueDouble = 0;
}

bool	BitcoinExchange::openFiles( char **argv)
{
	std::string line;
	std::string keyStr;
	std::string	valueStr;
	double		valueDouble;

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
		// TO DO MAY BE: VALIDATE INPUT
		valueDouble = std::atof(valueStr.c_str());
		_csvMap[keyStr] = valueDouble;
		// std::cout << "key = " << keyStr << "\tvalue = " << valueDouble << std::endl; // TO DELETE
		// std::cout << "key = " << keyStr << std::endl; // TO DELETE
		keyStr.clear();
		valueStr.clear();
	}
	// std::cout << "Varaibles before delete\nkey = " << keyStr << "\tvalue = " << valueDouble << std::endl; // TO DELETE
	resetVariables(line, keyStr, valueStr, valueDouble);
	// std::cout << "Varaibles after delete\nkey = " << keyStr << "\tvalue = " << valueDouble << std::endl; // TO DELETE
	while (std::getline(_userInputFile, line))
	{
		std::stringstream ss(line);

		std::getline(ss, keyStr, '|');
		std::getline(ss, valueStr, '|');
		// TO DO MAY BE: VALIDATE INPUT
		if (keyStr.length() > 10 )
			keyStr.erase(keyStr.length() - 1);
		valueDouble = std::atof(valueStr.c_str());
		_inputMap[keyStr] = valueDouble;
		std::cout << "key = " << keyStr << "\tvalue = " << valueDouble << std::endl;
		keyStr.clear();
		valueStr.clear();
	}
	_hisroticCsvFile.close();
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

void	BitcoinExchange::printResults( void )
{
	for (std::map<std::string, double>::iterator it = _inputMap.begin(); it != _inputMap.end(); it++)
	{
		std::cout << std::endl << "it first = " << it->first << "\tit second = " << it->second << std::endl;
		// std::cout << "_csvMap.count(it first) = " << _csvMap.count(it->first) << std::endl << std::endl;
		if ( validInput( it ) == true)
		{
			std::map<std::string, double>::iterator itup = _csvMap.upper_bound(it->first);
			if (itup != _csvMap.begin())
				itup--;
			std::cout << it->first << " => " << it->second << " = " << (it->second * itup->second) << std::endl;
		}
	}
}

bool	BitcoinExchange::validInput(std::map<std::string, double>::iterator it){
	if ( validDate( it->first ) == false)
	{
		std::cout << "Error: bad input => " << it->first << std::endl;
		return false;
	}
	else if ( it->second < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if ( it->second > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
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
