#include "PmergeMe.hpp"

void	PmergeMe::startMergeInsertVector( int argc, char **argv)
{
	gettimeofday(&_vectorStartTime, NULL);

	for (int i = 1; i < argc; i++)
		_inputVector.push_back(atoi(argv[i]));

	executeVectorSortingAlgorithm();

	gettimeofday(&_vectorEndTime, NULL);
	_vectorDuration = ((_vectorEndTime.tv_sec - _vectorStartTime.tv_sec) * 1000000) + (_vectorEndTime.tv_usec - _vectorStartTime.tv_usec);
	return;
}

void	PmergeMe::executeVectorSortingAlgorithm( void )
{
	std::vector<int>::iterator it;
	int vectorSize = _inputVector.size();

	for (int i = 0; i < vectorSize; i += RUN)
		insertionSortVector(i, std::min(i + RUN - 1, vectorSize - 1));

	for (int sizeOfChunk = RUN; sizeOfChunk < vectorSize; sizeOfChunk = 2 * sizeOfChunk)
	{
		for (int leftLimit = 0; leftLimit < vectorSize; leftLimit += 2 * sizeOfChunk)
		{
			int midPoint = leftLimit + sizeOfChunk - 1;
			int rightLImit = std::min(leftLimit + 2 * sizeOfChunk - 1, vectorSize - 1);
			if (midPoint < rightLImit)
				mergeVector(leftLimit, midPoint, rightLImit);
		}
	}
	// it = std::unique(_inputVector.begin(), _inputVector.end());
	// _inputVector.resize( std::distance(_inputVector.begin(), it ) );
}

void	PmergeMe::insertionSortVector( int leftLimit, int rightLimit )
{
	for (int i = leftLimit + 1; i <= rightLimit; i++)
	{
		int key = _inputVector[i];
		int j = i - 1;

		while (j >= leftLimit && _inputVector[j] > key)
		{
			_inputVector[j + 1] = _inputVector[j];
			j--;
		}
		_inputVector[j + 1] = key;
	}
}

void	PmergeMe::mergeVector( int leftLimit, int midPoint, int rightLimit )
{
	int					leftChunkSize = midPoint - leftLimit + 1;
	int					rightChunkSize = rightLimit - midPoint;
	std::vector<int>	leftChunk(leftChunkSize);
	std::vector<int>	rightChunk(rightChunkSize);

	for (int h = 0; h < leftChunkSize; h++)
		leftChunk[h] = _inputVector[leftLimit + h];

	for (int h = 0; h < rightChunkSize; h++)
		rightChunk[h] = _inputVector[midPoint + 1 + h];

	int i = 0;
	int j = 0;
	int _inputVectorIndex = leftLimit;
	while (i < leftChunkSize && j < rightChunkSize)
	{
		if (leftChunk[i] <= rightChunk[j])
		{
			_inputVector[_inputVectorIndex] = leftChunk[i];
			i++;
		}
		else
		{
			_inputVector[_inputVectorIndex] = rightChunk[j];
			j++;
		}
		_inputVectorIndex++;
	}
	while (i < leftChunkSize)
	{
		_inputVector[_inputVectorIndex] = leftChunk[i];
		i++;
		_inputVectorIndex++;
	}
	while (j < rightChunkSize)
	{
		_inputVector[_inputVectorIndex] = rightChunk[j];
		j++;
		_inputVectorIndex++;
	}
}
