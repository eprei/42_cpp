#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if ( argc != 2 )
		return rpn.printHelp();
	return (rpn.calculator(argv));
}
