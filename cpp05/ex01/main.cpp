#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	NEW_LINE;
 	std::cout << "____________ FORMULAIRE 1 _____________________" << std::endl;
	Form formulaire1;
	std::cout << formulaire1 << std::endl;

	std::cout << "____________ FORMULAIRE 2 _____________________" << std::endl;
	Form formulaire2("Long procedure", 125, 125);
	std::cout << formulaire2 << std::endl;

	NEW_LINE;
	std::cout << "____________ FORMULAIRE 3 _____________________" << std::endl;
	NEW_LINE;
	Form formulaire3(formulaire2);
	std::cout << formulaire3 << std::endl;

	NEW_LINE;
	std::cout << "____________ FORMULAIRE 4 _____________________" << std::endl;
	NEW_LINE;
	Form formulaire4("impossible procedure 1", 0, 125);

	NEW_LINE;
	std::cout << "____________ FORMULAIRE 5 _____________________" << std::endl;
	NEW_LINE;
	Form formulaire5("impossible procedure 2", 125, 151);

	NEW_LINE;
	std::cout << "____________ FORMULAIRE 6 _____________________" << std::endl;
	NEW_LINE;
	Form		formulaire6("Must be signed", 125, 125);
	std::cout << formulaire6 << std::endl;
	NEW_LINE;
	Bureaucrat	theNewEmployee("The new employee", 126);
	formulaire6.beSigned(theNewEmployee);
	std::cout << formulaire6 << std::endl;
	Bureaucrat	boss("The boss", 1);
	formulaire6.beSigned(boss);
	std::cout << formulaire6 << std::endl;

	NEW_LINE;
	std::cout << "____________ FORMULAIRE 7 _____________________" << std::endl;
	NEW_LINE;
	Form		formulaire7("Recruitment of new staff", 1, 1);
	std::cout << formulaire7 << std::endl;
	theNewEmployee.signForm(formulaire7);
	std::cout << formulaire7 << std::endl;
	boss.signForm(formulaire7);
	std::cout << formulaire7 << std::endl;

	return 0;
}
