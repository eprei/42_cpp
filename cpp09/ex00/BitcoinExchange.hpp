#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <stdio.h>
# include <string.h>
# include <string>
# include <stdlib.h>
# include <fstream>
# include <sstream>

class BitcoinExchange{

	public:

		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange( void );

		BitcoinExchange &	operator=( BitcoinExchange const & rhs );

		bool	startExchange( char **argv );
		bool	printError( int i , const std::string &str) const;
		bool	openFiles( char **argv );
		void	printResults( std::string &key, float &value );
		bool	validInput(std::string &key, float &value);
		bool	validDate(const std::string &str);
		bool	checkChars(std::string date);

	private:

		std::ifstream					_hisroticCsvFile;
		std::ifstream					_userInputFile;
		std::map<std::string, float>	_csvMap;
		std::map<std::string, float>	_inputMap;
};

#endif
