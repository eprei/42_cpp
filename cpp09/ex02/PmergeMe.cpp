#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ){}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe	&PmergeMe::operator=( PmergeMe const & rhs )
{
	if (this != &rhs)
	{
		this->_inputVector = rhs._inputVector;
		this->_vectorStartTime = rhs._vectorStartTime;
		this->_vectorEndTime = rhs._vectorEndTime;
		this->_vectorDuration = rhs._vectorDuration;
		this->_inputList = rhs._inputList;
		this->_listStartTime = rhs._listStartTime;
		this->_listEndTime = rhs._listEndTime;
		this->_listDuration = rhs._listDuration;
	}
	return *this;
}

int		PmergeMe::printError( void ) const
{
	std::cout << "Error" << std::endl;
	return EXIT_FAILURE;
}

int		PmergeMe::printError( std::string str ) const
{
	std::cout << "Error: " << str << std::endl;
	return EXIT_FAILURE;
}

int		PmergeMe::printError( std::string str , int i ) const
{
	std::cout << "Error: " << str << i << "th element" << std::endl;
	return EXIT_FAILURE;
}

int		PmergeMe::startProcess( int argc, char **argv )
{
	if (checkArgs(argc, argv) == EXIT_FAILURE )
		return EXIT_FAILURE;
	startMergeInsertVector(argc, argv);
	startMergeInsertList(argc, argv);
	printResults();
	return EXIT_SUCCESS;
}

int		PmergeMe::checkArgs( int argc, char **argv )
{
	long valueConverted;

	_originalInput = argv;
	for (int i = 1; i < argc; i++)
	{
		int j = 0;

		while (argv[i][j] != '\0')
		{
			if ( j > 10 )
				return printError("int overflow found at the ", i);
			if (!isdigit(argv[i][j]))
				return printError("found at the ", i);
			j++;
		}
		valueConverted = std::strtol(argv[i], NULL, 10);
		if (valueConverted > INT_MAX )
			return printError("int overflow found at the ", i);
	}
	return EXIT_SUCCESS;
}

// TO DO: the right print the ordered secuence and may be test thath both containers has the same result
void	PmergeMe::printResults( void )
{
	std::cout << "Before:\t\t\t";
	for (size_t i = 1; _originalInput[i] != 0 ; i++)
		std::cout << _originalInput[i] << " ";

	std::cout << std::endl << "After with vector:\t";
	for (std::vector<int>::iterator it = _inputVector.begin(); it != _inputVector.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "After with list:\t";
	for (std::list<int>::iterator it = _inputList.begin(); it != _inputList.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "Time to process a range of " << _inputVector.size() << " elements with std::vector :" << _vectorDuration << " us" << std::endl;
	std::cout << "Time to process a range of " << _inputList.size() << " elements with std::list :" << _listDuration << " us" << std::endl;

	return;
}
