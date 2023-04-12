#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pme;

	if (argc == 1)
		return pme.printError();
	std::cout << "argc = " << argc << std::endl;
	return pme.startProcess( argc, argv );
}
