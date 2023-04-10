#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bex;

	if (argc == 2)
		return bex.startExchange( argv );
	std::cout << "Error: could not open file." << std::endl;
	return 1;
}
