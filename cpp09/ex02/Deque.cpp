#include "PmergeMe.hpp"

void	PmergeMe::startMergeInsertDeque( int argc, char **argv)
{
	gettimeofday(&_dequeStartTime, NULL);

	for (int i = 1; i < argc; i++)
		_inputDeque.push_back(atoi(argv[i]));

	executeDequeSortingAlgorithm();

	gettimeofday(&_dequeEndTime, NULL);
	_dequeDuration = ((_dequeEndTime.tv_sec - _dequeStartTime.tv_sec) * 1000000) + (_dequeEndTime.tv_usec - _dequeStartTime.tv_usec);
	return;
}

void	PmergeMe::executeDequeSortingAlgorithm( void )
{
	std::deque<int>::iterator it;
	int dequeSize = _inputDeque.size();

	for (int i = 0; i < dequeSize; i += RUN)
		insertionSortDeque(i, std::min(i + RUN - 1, dequeSize - 1));

	for (int sizeOfChunk = RUN; sizeOfChunk < dequeSize; sizeOfChunk = 2 * sizeOfChunk)
	{
		for (int leftLimit = 0; leftLimit < dequeSize; leftLimit += 2 * sizeOfChunk)
		{
			int midPoint = leftLimit + sizeOfChunk - 1;
			int rightLImit = std::min(leftLimit + 2 * sizeOfChunk - 1, dequeSize - 1);
			if (midPoint < rightLImit)
				mergeDeque(leftLimit, midPoint, rightLImit);
		}
	}
}

void	PmergeMe::insertionSortDeque( int leftLimit, int rightLimit )
{
	for (int i = leftLimit + 1; i <= rightLimit; i++)
	{
		int key = _inputDeque[i];
		int j = i - 1;

		while (j >= leftLimit && _inputDeque[j] > key)
		{
			_inputDeque[j + 1] = _inputDeque[j];
			j--;
		}
		_inputDeque[j + 1] = key;
	}
}

void	PmergeMe::mergeDeque( int leftLimit, int midPoint, int rightLimit )
{
	int					leftChunkSize = midPoint - leftLimit + 1;
	int					rightChunkSize = rightLimit - midPoint;
	std::deque<int>	leftChunk(leftChunkSize);
	std::deque<int>	rightChunk(rightChunkSize);

	for (int h = 0; h < leftChunkSize; h++)
		leftChunk[h] = _inputDeque[leftLimit + h];

	for (int h = 0; h < rightChunkSize; h++)
		rightChunk[h] = _inputDeque[midPoint + 1 + h];

	int i = 0;
	int j = 0;
	int _inputDequeIndex = leftLimit;
	while (i < leftChunkSize && j < rightChunkSize)
	{
		if (leftChunk[i] <= rightChunk[j])
		{
			_inputDeque[_inputDequeIndex] = leftChunk[i];
			i++;
		}
		else
		{
			_inputDeque[_inputDequeIndex] = rightChunk[j];
			j++;
		}
		_inputDequeIndex++;
	}
	while (i < leftChunkSize)
	{
		_inputDeque[_inputDequeIndex] = leftChunk[i];
		i++;
		_inputDequeIndex++;
	}
	while (j < rightChunkSize)
	{
		_inputDeque[_inputDequeIndex] = rightChunk[j];
		j++;
		_inputDequeIndex++;
	}
}
