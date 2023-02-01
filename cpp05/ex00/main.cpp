#include "Bureaucrat.hpp"
# define NEW_LINE std::cout << std::endl

int main()
{
	// These first two should not work as the grades are not valid
	Bureaucrat Frank("Frank", 0);
	Bureaucrat Thomas("Thomas", 151);

	Bureaucrat alexBadEmployee("Alex", 1);
	NEW_LINE;
	std::cout << "___   alexBadEmployee descends to the bottom   ___" << std::endl;
	NEW_LINE;
	std::cout << alexBadEmployee;
	for (int i = 0; i < 150; i++)
	{
		alexBadEmployee.decreaseDegree();
		if ((i + 2) % 10 == 0)
			std::cout << alexBadEmployee;
	}

	NEW_LINE;
	Bureaucrat alexGoodEmployee(alexBadEmployee);
	NEW_LINE;

	std::cout << "___    alexGoodEmployee ascends to the highest   ___" << std::endl;
	NEW_LINE;
	std::cout <<  alexGoodEmployee;
	for (int i = 149; i >= 0; i--)
	{
		 alexGoodEmployee.increaseDegree();
		if (i % 10 == 0)
			std::cout <<  alexGoodEmployee;
	}
	NEW_LINE;
	return 0;
}
