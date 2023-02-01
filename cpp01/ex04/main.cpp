#include "Replacer.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	Replacer	rep;
	if (argc != 4)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		std::cout << "Correct usage: ./replacer <filename> <string to replace> <new string>" << std::endl;
		return 1;
	}
	if (rep.getArgs(argv))
		rep.execReplacement();
	else
	{
		std::cout << "Error: " << argv[1] << " could not be opened" <<std::endl;
		return 1;
	}
	return 0;
}
