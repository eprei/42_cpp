#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form* robotomy;
	Form* shrubbery;
	Form* presidential;

	std::cout << std::boolalpha;
	NEW_LINE;
	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Penelope");
	NEW_LINE;
	std::cout << "*****\tShrubbery form info\t*****" << std::endl;
	std::cout << "Name: " << shrubbery->getName() << std::endl;
	std::cout << "Grade to signe: " << shrubbery->getGradeToSigne() << std::endl;
	std::cout << "Grade to execute: " << shrubbery->getGradeToExecute() << std::endl;
	std::cout << "Get signed: " << shrubbery->getSigned() << std::endl;
	std::cout << "Target: " << static_cast<ShrubberyCreationForm*>(shrubbery)->getTarget() << std::endl;

	NEW_LINE;
	robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	NEW_LINE;
	std::cout << "*****\tRobotomy form info\t*****" << std::endl;
	std::cout << "Name: " << robotomy->getName() << std::endl;
	std::cout << "Grade to signe: " << robotomy->getGradeToSigne() << std::endl;
	std::cout << "Grade to execute: " << robotomy->getGradeToExecute() << std::endl;
	std::cout << "Get signed: " << robotomy->getSigned() << std::endl;
	std::cout << "Target: " << static_cast<RobotomyRequestForm*>(robotomy)->getTarget() << std::endl;

	NEW_LINE;
	presidential = someRandomIntern.makeForm("presidential pardone", "Grace");
	presidential = someRandomIntern.makeForm("presidential pardo", "Grace");
	presidential = someRandomIntern.makeForm("presidential pardon", "Grace");
	NEW_LINE;
	std::cout << "*****\tPresidential form info\t*****" << std::endl;
	std::cout << "Name: " << presidential->getName() << std::endl;
	std::cout << "Grade to signe: " << presidential->getGradeToSigne() << std::endl;
	std::cout << "Grade to execute: " << presidential->getGradeToExecute() << std::endl;
	std::cout << "Get signed: " << presidential->getSigned() << std::endl;
	std::cout << "Target: " << static_cast<PresidentialPardonForm*>(presidential)->getTarget() << std::endl;

	delete robotomy;
	delete shrubbery;
	delete presidential;

	NEW_LINE;

	return 0;
}
