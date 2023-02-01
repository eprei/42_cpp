#include "Fixed.hpp"
#include <iostream>
#include <math.h>

const int Fixed::_nOfBitsFraction = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed ( const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << Fixed::_nOfBitsFraction;
	return ;
}

Fixed::Fixed ( const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = round (f * pow(2, Fixed::_nOfBitsFraction));
		return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return ((float)( this->_value * pow(2, (-1 * Fixed::_nOfBitsFraction))));
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> Fixed::_nOfBitsFraction);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}
