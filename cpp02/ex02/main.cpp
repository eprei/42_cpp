#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed x = 55;
	Fixed y = 54;

	std::cout << std::endl << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	std::cout << std::boolalpha;
	std::cout << std::endl << "6 comparison operator" << std::endl << std::endl;
	std::cout << "x < y :\t\t" << (x < y) << std::endl;
	std::cout << "x > y :\t\t" << (x > y) << std::endl;
	std::cout << "x >= y :\t" << (x >= y) << std::endl;
	std::cout << "x <= y :\t" << (x <= y) << std::endl;
	std::cout << "x == y :\t" << (x == y) << std::endl;
	std::cout << "x != y :\t" << (x != y) << std::endl << std::endl;

	std::cout << std::endl << "4 arithmetic operators" << std::endl << std::endl;
	std::cout << "x + y :\t" << x + y << std::endl;
	std::cout << "x - y :\t" << x - y << std::endl;
	std::cout << "x * y :\t" << x * y << std::endl;
	std::cout << "x / y :\t" << x / y << std::endl;

	std::cout << std::endl << "4 increment and decrement operators" << std::endl << std::endl;
	std::cout << "x :\t" << x << std::endl;
	std::cout << "++x :\t" << ++x << std::endl;
	std::cout << "x++ :\t" << x++ << std::endl;
	std::cout << "x :\t" << x << std::endl;
	std::cout << "y :\t" << y << std::endl;
	std::cout << "--y :\t" << --y << std::endl;
	std::cout << "y-- :\t" << y-- << std::endl;
	std::cout << "y :\t" << y << std::endl;

	std::cout << std::endl << "min and max functions" << std::endl << std::endl;
	std::cout << "min between x & y : " << Fixed::min(x, y) << std::endl;
	std::cout << "max between x & y : " << Fixed::max(x, y) << std::endl;

	std::cout << std::endl << "Test suggested by the subject" << std::endl << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;

}
