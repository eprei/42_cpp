#include "RPN.hpp"

RPN::RPN( void ){}

RPN::RPN( RPN const & src )
{
	*this = src;
	return ;
}

RPN::~RPN( void ) {}

RPN &	RPN::operator=( RPN const & rhs )
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
		this->_input = rhs._input;
	}
	return *this;
}

bool	RPN::calculator( char **argv )
{
	if (!checkArgs( argv ))
		return printHelp();
	return startCalculations();
}

bool	RPN::checkArgs( char **argv )
{
	_input = argv[1];

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (!strchr(ALLOWED_CHARACTERES, _input[i]))
			return false;
	}
	return true;
}

bool	RPN::printHelp( void ) const
{
		std::cout << RED << PRINT_USAGE_MESSAGE << std::endl;
		std::cout << GREEN << PRINT_FORMAT_MESSAGE << RESET << std::endl;
		std::cout << GREEN << "Allowed characters: " << RESET << ALLOWED_CHARACTERES << std::endl;
		std::cout << GREEN << PRINT_EXAMPLE_MESSAGE << RESET << std::endl;
		return false;
}

bool	RPN::startCalculations( void )
{
	int numberExtracted;

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (strchr(ALLOWED_NUMBERS, _input[i]))
		{
			std::string charString(1, _input[i]);
			numberExtracted = std::atoi(charString.c_str());
			_stack.push(numberExtracted);
		}
		else if (isOperator(_input[i]))
			doTheMath(_input[i]);
	}
	std::cout << _stack.top() << std::endl;
	return true;
}

bool	RPN::isOperator(const char c) const
{
	return (strchr(ALLOWED_OPERATORS, c));
}

void	RPN::doTheMath( const char c )
{
	int	rightValue;
	int	leftValue;
	int	result;

	if ( _stack.size() > 1)
	{
		rightValue = _stack.top();
		_stack.pop();
		leftValue = _stack.top();
		_stack.pop();

		if (c == '+')
			result = leftValue + rightValue;
		else if (c == '-')
			result = leftValue - rightValue;
		else if (c == '*')
			result = leftValue * rightValue;
		else if (c == '/')
		{
			if ( rightValue == 0 )
			{
				std::cout << "Error: division by zero is considered as undefined" << std::endl;
				exit (EXIT_FAILURE);
			}
			else
				result = leftValue / rightValue;
		}
		_stack.push(result);
	}
}
