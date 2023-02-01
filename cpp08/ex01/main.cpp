#include "Span.hpp"
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <climits>
#include <list>

int main()
{
	// TEST WITH SPAN OF SIZE 5
	std::cout << std::endl << "____\t\tTEST WITH SPAN OF SIZE 5\t\t_____" << std::endl << std::endl;

	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(6);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	sp.addNumber(17);
	sp.addNumber(7);
	sp.addNumber(9);
	sp.addNumber(55);
	try
	{
		sp.addNumber(99);
	}
	catch( const Span::notSpace& oor )
	{
		std::cerr << "Impossible to add the new element. Span has already assigned the maximum number of possible elements" << std::endl;
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST WITH SPAN OF SIZE 500.000
	std::cout << std::endl << "____\t\tTEST WITH SPAN OF SIZE 500.000\t\t_____" << std::endl << std::endl;

	Span big = Span(500000);
	int		randomNumber;
	int		highestRandomlyGeneratedNumber = INT_MIN;
	int		smallestRandomlyGeneratedNumber = INT_MAX;

	srand(time(NULL));
	for (int i = 0; i < 500000; i++)
	{
		randomNumber = rand();
		big.addNumber(randomNumber);
		if (randomNumber < smallestRandomlyGeneratedNumber)
			smallestRandomlyGeneratedNumber = randomNumber;
		if (randomNumber > highestRandomlyGeneratedNumber)
			highestRandomlyGeneratedNumber = randomNumber;
	}

	std::cout << "Highest Random Number Generated = " << highestRandomlyGeneratedNumber << std::endl;
	std::cout << "Smallest Random Number Generated = " << smallestRandomlyGeneratedNumber << std::endl;
	std::cout << "Biggest difference = " << highestRandomlyGeneratedNumber - smallestRandomlyGeneratedNumber << std::endl;
	std::cout << "Biggest difference calculated with the function longestSpan = " << big.longestSpan() << std::endl;
	if (big.longestSpan() == static_cast<unsigned int>(highestRandomlyGeneratedNumber - smallestRandomlyGeneratedNumber))
		std::cout << "\n\t\t_-_-_-_\tTEST SUCCESSFUL\t_-_-_-_" << std::endl;
	else
		std::cout << "_-_-_-_\tTEST FAILED\t_-_-_-_" << std::endl;
	std::cout << std::endl;

	// TEST COPYING MULTIPLE ELEMENTS BY USING RANGE OF ITERATORS
	std::cout << std::endl << "____\tTEST COPYING MULTIPLE ELEMENTS BY USING RANGE OF ITERATORS\t_____" << std::endl << std::endl;

	Span 				multiElements = Span(10);
	std::vector<int>	toBeCopiedFromVector;

	std::cout << "==>\tPrinting MultiElements before any copying" << std::endl << std::endl;
	std::cout << multiElements;
	std::cout << std::endl << "==>\tCopying elements from a vector ..." << std::endl;
	for (int i = 0; i < 10; i++)
		toBeCopiedFromVector.push_back(i);
	try
	{
		multiElements.addRangeOfNumbers(toBeCopiedFromVector.begin(), toBeCopiedFromVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "==>\tPrinting MultiElements after copying from vector" << std::endl << std::endl;
	std::cout << multiElements;
	return 0;
}
