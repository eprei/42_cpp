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
		this->_stack = rhs._stack;
	return *this;
}

bool	RPN::calculator( char **argv )
{
	if (!checkArgs( argv ))
		return printHelp();
	return startCalculations();
}

bool	RPN::checkArgs( char **argv ) {
	size_t operators = 0;
	size_t operands = 0;
	_input = argv[1];

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (!std::strchr(ALLOWED_CHARACTERES, _input[i]))
			return false;
		else if (std::strchr(ALLOWED_OPERATORS, _input[i]))
			operators++;
		else if (_input[i] != ' ')
			operands++;
	}
	return (operators + 1 == operands);
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
		if (std::strchr(ALLOWED_NUMBERS, _input[i]))
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
	return (std::strchr(ALLOWED_OPERATORS, c));
}

void	RPN::doTheMath( const char c )
{
	int	rightValue;
	int	leftValue;
	int	result;

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
		result = leftValue / rightValue;

	_stack.push(result);
}
