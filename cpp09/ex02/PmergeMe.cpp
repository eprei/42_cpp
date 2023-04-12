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
	mergeInsertVector(argc, argv);
	mergeInsertList(argc, argv);
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

void	PmergeMe::mergeInsertVector( int argc, char **argv)
{
	gettimeofday(&_vectorStartTime, NULL);

	for (int i = 1; i < argc; i++)
		_inputVector.push_back(atoi(argv[i]));

	// executeVectorSortingAlgorithm();
	mergeInsertSort(_inputVector);

	gettimeofday(&_vectorEndTime, NULL);
	_vectorDuration = ((_vectorEndTime.tv_sec - _vectorStartTime.tv_sec) * 1000000) + (_vectorEndTime.tv_usec - _vectorStartTime.tv_usec);
	return;
}

// TO DO: the right print the ordered secuence and may be test thath both containers has the same result
void	PmergeMe::printResults( void )
{
	std::cout << "Before:\t";

	for (size_t i = 1; _originalInput[i] != 0 ; i++)
		std::cout << _originalInput[i] << " ";

	std::cout << std::endl << "After:\t";

	for (std::vector<int>::iterator it = _inputVector.begin(); it != _inputVector.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "Time to process a range of " << _inputVector.size() << " elements with std::vector :" << _vectorDuration << " us" << std::endl;
	std::cout << "Time to process a range of " << _inputList.size() << " elements with std::list :" << _listDuration << " us" << std::endl;

	return;
}

void	PmergeMe::mergeInsertList( int argc, char **argv)
{
	gettimeofday(&_listStartTime, NULL);

	for (int i = 1; i < argc; i++)
		_inputList.push_back(atoi(argv[i]));

	gettimeofday(&_listEndTime, NULL);
	_listDuration = ((_listEndTime.tv_sec - _listStartTime.tv_sec) * 1000000) + (_listEndTime.tv_usec - _listStartTime.tv_usec);
	return;
}


// void	PmergeMe::insertionSortVector( int leftLimit, int rightLimit )
// {
// 	for (int i = leftLimit + 1; i <= rightLimit; i++)
// 	{
// 		int key = _inputVector[i];
// 		int j = i - 1;

// 		while (j >= leftLimit && _inputVector[j] > key)
// 		{
// 			_inputVector[j + 1] = _inputVector[j];
// 			j--;
// 		}
// 		_inputVector[j + 1] = key;
// 	}
// }

// void	PmergeMe::mergeSortVector( int leftLimit, int midPoint, int rightLimit )
// {
// 	int leftChunkSize = midPoint - leftLimit + 1;
// 	int rightChunkSize = rightLimit - midPoint;

// 	std::vector<int> leftChunk(leftChunkSize);
// 	std::vector<int> rightChunk(rightChunkSize);

// 	int i = 0;
// 	int j = 0;
// 	int k = leftLimit;

// 	for (int itL = 0; itL < leftChunkSize; itL++)
// 		leftChunk[itL] = _inputVector[leftLimit + i];

// 	for (int itR = 0; itR < rightChunkSize; itR++)
// 		rightChunk[itR] = _inputVector[midPoint + 1 + i];

// 	while (i < leftChunkSize && j < rightChunkSize)
// 	{
// 		if (leftChunk[i] <= rightChunk[j])
// 		{
// 			_inputVector[k] = leftChunk[i];
// 			i++;
// 		}
// 		else
// 		{
// 			_inputVector[k] = rightChunk[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while (i < leftChunkSize)
// 	{
// 		_inputVector[k] = leftChunk[i];
// 		i++;
// 		k++;
// 	}
// 	while (j < rightChunkSize) {
// 		_inputVector[k] = rightChunk[j];
// 		j++;
// 		k++;
// 	}
// }

// void	PmergeMe::executeVectorSortingAlgorithm( void )
// {
// 	std::vector<int>::iterator it;
// 	int vectorSize = _inputVector.size();

// 	for (int limitLeft = 0; limitLeft < vectorSize; limitLeft += RUN)
// 		insertionSortVector(limitLeft, std::min(limitLeft + RUN - 1, vectorSize - 1));

// 	for (int size = RUN; size < vectorSize; size = 2 * size)
// 	{
// 		for (int leftLimitToMerge = 0; leftLimitToMerge < vectorSize; leftLimitToMerge += 2 * size)
// 		{
// 			int midPoint = leftLimitToMerge + size - 1;
// 			int rightLimitToMerge = std::min(leftLimitToMerge + 2 * size - 1, vectorSize - 1);
// 			mergeSortVector(leftLimitToMerge, midPoint, rightLimitToMerge);
// 		}
// 	}
// 	// it = std::unique(_inputVector.begin(), _inputVector.end());
// 	// _inputVector.resize( std::distance(_inputVector.begin(), it ) );
// }

void	PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + 1 + i];
	}
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
	int n = arr.size();
	int minRun = 32;
	for (int i = 0; i < n; i += minRun) {
		insertionSort(arr, i, std::min(i + minRun - 1, n - 1));
	}
	for (int size = minRun; size < n; size = 2 * size) {

		for (int left = 0; left < n; left += 2 * size)
		{
			int mid = left + size - 1;

			int right = std::min(left + 2 * size - 1, n - 1);
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}
