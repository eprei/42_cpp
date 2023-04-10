#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RESET					"\033[0m"
# define RED					"\033[31m"
# define GREEN					"\033[32m"
# define YELLOW					"\033[33m"

# include <iostream>
# include <map>
# include <stdio.h>
# include <string.h>
# include <string>
# include <stdlib.h>
# include <fstream>
# include <sstream>

// TO DO: CHANGE DOUBLE TO FLOAT IN MAPS !!!
//			and solve Error: bad input => date
// TO CONSIDER: when user do 2001-42-42 with no second argument
class BitcoinExchange{

	public:

		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange( void );

		BitcoinExchange &	operator=( BitcoinExchange const & rhs );

		bool	startExchange( char **argv );
		bool	printError( int i , const std::string &str) const;
		bool	openFiles( char **argv );
		void	printResults( void );
		bool	validInput(std::map<std::string, double>::iterator it);
		bool	validDate(const std::string &str);
		bool	checkChars(std::string date);

	private:

		std::ifstream					_hisroticCsvFile;
		std::ifstream					_userInputFile;
		std::map<std::string, double>	_csvMap;
		std::map<std::string, double>	_inputMap;
};

#endif
