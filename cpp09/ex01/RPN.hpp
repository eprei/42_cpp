#ifndef RPN_HPP
# define RPN_HPP

# define RESET					"\033[0m"
# define RED					"\033[31m"
# define GREEN					"\033[32m"
# define YELLOW					"\033[33m"
# define ALLOWED_CHARACTERES	"01234567890+-/* "
# define ALLOWED_NUMBERS		"01234567890"
# define ALLOWED_OPERATORS		"+-/*"
# define PRINT_USAGE_MESSAGE	">>\tError found in the given input\t<<"
# define PRINT_FORMAT_MESSAGE	"Program execution format: \033[0m./RPN \" (operators and operands in RPN format) \""
# define PRINT_EXAMPLE_MESSAGE	"Example of valid input:\033[0m ./RPN \"1 2 * 2 / 2 * 2 4 - +\""

# include <iostream>
# include <stack>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

class RPN{

	public:

		RPN( void );
		RPN( RPN const & src );
		~RPN( void );

		RPN &	operator=( RPN const & rhs );

		bool	calculator( char **argv );
		bool	checkArgs( char **argv );
		bool	printHelp( void ) const;
		bool	startCalculations( void );
		bool	isOperator( const char c ) const;
		void	doTheMath( const char c );

	private:

		std::string			_input;
		std::stack<double>	_stack;
};

#endif
