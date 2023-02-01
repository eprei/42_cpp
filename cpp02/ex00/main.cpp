#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	// Fixed e;

	c = b;
	// e.setRawBits(55);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	// std::cout << e.getRawBits() << std::endl;
	return 0;
}
