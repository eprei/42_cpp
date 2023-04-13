#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pme;

	if (argc == 1)
		return pme.printError();
	return pme.startProcess( argc, argv );
}
