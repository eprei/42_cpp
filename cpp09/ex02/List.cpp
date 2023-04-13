#include "PmergeMe.hpp"

void	PmergeMe::startMergeInsertList( int argc, char **argv)
{
	gettimeofday(&_listStartTime, NULL);

	for (int i = 1; i < argc; i++)
		_inputList.push_back(atoi(argv[i]));

	executeListSortingAlgorithm();

	gettimeofday(&_listEndTime, NULL);
	_listDuration = ((_listEndTime.tv_sec - _listStartTime.tv_sec) * 1000000) + (_listEndTime.tv_usec - _listStartTime.tv_usec);
	return;
}

std::list<int>::iterator add(std::list<int>::iterator it, int i )
{
	while (i > 0)
	{
		++it;
		--i;
	}
	return it;
}

std::list<int>::iterator next(std::list<int>::iterator it, int i )
{
	std::list<int>::iterator add = it;

	while (i > 0)
	{
		++add;
		--i;
	}
	return add;
}

std::list<int>::iterator before(std::list<int>::iterator it, int i )
{
	std::list<int>::iterator rest = it;

	while (i < 0)
	{
		--rest;
		++i;
	}
	return rest;
}

std::list<int>::iterator subtract(std::list<int>::iterator it, int i )
{
	while (i < 0)
	{
		--it;
		++i;
	}
	return it;
}

std::list<int>::iterator PmergeMe::addRunSizeOrToTheTnd(std::list<int>::iterator it )
{
	int i = RUN;

	while (i > 0 && it != _inputList.end())
	{
		++it;
		--i;
		std::cout << "add -> i = " << i << "\t*it = " << *it << std::endl;
	}
	return it;
}


void PmergeMe::executeListSortingAlgorithm( void )
{
	// int listSize = _inputList.size();

	for (std::list<int>::iterator i = _inputList.begin(); i != _inputList.end(); i = addRunSizeOrToTheTnd(i))
	{
		std::cout << YELLOW << "\tSOS VOS EL PROBLEMA\n" << RESET;
		std::list<int>::iterator rightLimit = i;
		for (int i = 0; i < RUN && rightLimit != --_inputList.end() ; i++)
			rightLimit++;
		std::cout << "before send to insertion" << std::endl;
		printList(i, rightLimit);
		insertionSortList(i, rightLimit);

	}

	// for (int sizeOfChunk = RUN; sizeOfChunk < listSize; sizeOfChunk = 2 * sizeOfChunk)
	// { // TO DO!!! FROM HERE< CHECK SUBSTITUIR NEXT WITH ADVANCE
	// 	for (std::list<int>::iterator leftLimit = _inputList.begin(); leftLimit != _inputList.end(); leftLimit = next(leftLimit, 2 * sizeOfChunk))
	// 	{
	// 		// std::list<int>::iterator midPoint = std::next(leftLimit, sizeOfChunk);
	// 		// std::list<int>::iterator rightLimit = std::next(leftLimit, 2 * sizeOfChunk);
	// 		std::list<int>::iterator midPoint = next(leftLimit, sizeOfChunk);
	// 		std::list<int>::iterator rightLimit = next(leftLimit, 2 * sizeOfChunk);
	// 		if (midPoint != _inputList.end() && rightLimit != _inputList.end())
	// 			mergeList(leftLimit, midPoint, rightLimit);
	// 	}
	// }
	// std::unique(_inputList.begin(), _inputList.end());
	// _inputList.erase(std::unique(_inputList.begin(), _inputList.end()), _inputList.end());
}

void		PmergeMe::insertionSortList(std::list<int>::iterator leftLimit, std::list<int>::iterator rightLimit)
{
	std::list<int>::iterator begin = before(leftLimit, - 1);
	std::list<int>::iterator end = next(rightLimit, 1);

	std::cout << "print chunk before\n";
	printList(leftLimit, rightLimit);

	for (std::list<int>::iterator i = next(leftLimit, 1); i != end; i++)
	{
		int key = *i;
		std::list<int>::iterator j = before(i, -1);
		bool	doReplacement = false;

		// std::cout << "\n*j = " << *j << "\t*i = " << *i << std::endl;

		std::list<int>::iterator aux = j;

		while ( aux != begin )
		{
			// std::cout << GREEN << "bucle" << RESET << std::endl;
			// std::cout << "before j--\t*j: " << *j << "\t*i: " << *i << std::endl;
			// std::cout << MAGENTA << "*aux = " << RESET << *aux << std::endl;
			// std::cout << MAGENTA << "*aux-- = " << RESET << *aux  << "\tkey = " << key << "\t*aux > key = " << std::boolalpha << (*aux > key) <<  "\taux != begin: " << (aux != begin) << "\tasignation = "<< (aux != begin && *aux > key) << std::endl;

			if (aux != begin && *aux > key)
			{
				j = aux;
				doReplacement = true;
				// std::cout << "after j--\t*j: " << *j << "\t*i: " << *i << std::endl;
			}
			aux--;
		}
		if(doReplacement == true)
		{
			// std::cout << "\tbefore insert";
			// printList();
			_inputList.insert(j, key);
			// std::cout << "\tafter insert";
			// printList();
			_inputList.erase(i);
		}
	}
	std::cout << "print chunk after\n";
	printList(next(begin, 1), before(end, -1));
}

void		PmergeMe::mergeList(std::list<int>::iterator leftLimit, std::list<int>::iterator midPoint, std::list<int>::iterator rightLimit)
{
	std::list<int> leftChunk;
	std::list<int> rightChunk;

	for (std::list<int>::iterator it = leftLimit; it != midPoint; ++it)
		leftChunk.push_back(*it);

	for (std::list<int>::iterator it = midPoint; it != rightLimit; ++it)
		rightChunk.push_back(*it);

	std::list<int>::iterator i = leftChunk.begin();
	std::list<int>::iterator j = rightChunk.begin();
	std::list<int>::iterator k = leftLimit;

	while (i != leftChunk.end() && j != rightChunk.end())
	{
		if (*i <= *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}

	while (i != leftChunk.end())
	{
		*k = *i;
		++i;
		++k;
	}

	while (j != rightChunk.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

void	PmergeMe::printList()
{
	std::cout << "\n>>\tPRINTING LIST\t<<" << std::endl;
	for (std::list<int>::iterator it = _inputList.begin(); it != _inputList.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	// std::cout << ">>\tPRINTING LIST with interval\t<<" << std::endl;
	for (std::list<int>::iterator it = begin; it != end; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


