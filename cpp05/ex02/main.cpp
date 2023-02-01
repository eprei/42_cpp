#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// TEST ShrubberyCreationForm CLASS
	NEW_LINE;
 	std::cout << "____________ ShrubberyCreationForm _____________________" << std::endl;
	NEW_LINE;
	ShrubberyCreationForm Shrubbery("Jardin");

	NEW_LINE;
	Bureaucrat	PaulCantSign("Paul", 146);
	Bureaucrat	MarkCanSign("Mark", 145);
	Bureaucrat	AnneCantExecute("Anne", 138);
	Bureaucrat	SophieCanExecute("Sophie", 137);
	NEW_LINE;

	std::cout << "SophieCanExecute will try to execute an unsigned ShrubberyCreationForm" << std::endl;
	Shrubbery.execute(SophieCanExecute);

	NEW_LINE;
	std::cout << "PaulCantSign will try to sign the unsigned ShrubberyCreationForm" << std::endl;
	Shrubbery.beSigned(PaulCantSign);

	NEW_LINE;
	std::cout << "MarkCanSign will sign the unsigned ShrubberyCreationForm" << std::endl;
	Shrubbery.beSigned(MarkCanSign);

	NEW_LINE;
	std::cout << "AnneCantExecute will try to execute the already signed ShrubberyCreationForm" << std::endl;
	Shrubbery.execute(AnneCantExecute);
	std::cout << "AnneCantExecute will try to execute ShrubberyCreationForm from its member function" << std::endl;
	AnneCantExecute.executeForm(Shrubbery);

	NEW_LINE;
	std::cout << "SophieCanExecute will execute the already signed ShrubberyCreationForm" << std::endl;
	Shrubbery.execute(SophieCanExecute);
	std::cout << "SophieCanExecute will try to execute ShrubberyCreationForm from its member function" << std::endl;
	SophieCanExecute.executeForm(Shrubbery);

	// TEST RobotomyRequestForm CLASS

	NEW_LINE;
 	std::cout << "____________ RobotomyRequestForm _____________________" << std::endl;
	NEW_LINE;
	RobotomyRequestForm robo("Terminator");

	NEW_LINE;
	Bureaucrat	TomCantSign("Tom", 73);
	Bureaucrat	PhilCanSign("Phil", 72);
	Bureaucrat	OliviaCantExecute("Olivia", 46);
	Bureaucrat	EmmaCanExecute("Emma", 45);
	NEW_LINE;

	std::cout << "EmmaCanExecute will try to execute an unsigned RobotomyRequestForm" << std::endl;
	robo.execute(EmmaCanExecute);

	NEW_LINE;
	std::cout << "TomCantSign will try to sign the unsigned RobotomyRequestForm" << std::endl;
	robo.beSigned(TomCantSign);

	NEW_LINE;
	std::cout << "PhilCanSign will sign the unsigned RobotomyRequestForm" << std::endl;
	robo.beSigned(PhilCanSign);

	NEW_LINE;
	std::cout << "OliviaCantExecute will try to execute the already signed RobotomyRequestForm" << std::endl;
	robo.execute(OliviaCantExecute);
	std::cout << "OliviaCantExecute will try to execute RobotomyRequestForm from its member function" << std::endl;
	OliviaCantExecute.executeForm(robo);

	NEW_LINE;
	std::cout << "EmmaCanExecute will execute the already signed RobotomyRequestForm" << std::endl;
	robo.execute(EmmaCanExecute);
	robo.execute(EmmaCanExecute);
	robo.execute(EmmaCanExecute);
	robo.execute(EmmaCanExecute);
	robo.execute(EmmaCanExecute);
	std::cout << "EmmaCanExecute will try to execute RobotomyRequestForm from its member function" << std::endl;
	EmmaCanExecute.executeForm(robo);

	// TEST PresidentialPardonForm CLASS

	NEW_LINE;
 	std::cout << "____________ PresidentialPardonForm _____________________" << std::endl;
	NEW_LINE;
	PresidentialPardonForm dany("Danny DeVito");

	NEW_LINE;
	Bureaucrat	JamesCantSign("James", 26);
	Bureaucrat	WilliamCanSign("William", 25);
	Bureaucrat	CharlotteCantExecute("Charlotte", 6);
	Bureaucrat	IsabellaCanExecute("Isabella", 5);
	NEW_LINE;

	std::cout << "IsabellaCanExecute will try to execute an unsigned PresidentialPardonForm" << std::endl;
	dany.execute(IsabellaCanExecute);

	NEW_LINE;
	std::cout << "JamesCantSign will try to sign the unsigned PresidentialPardonForm" << std::endl;
	dany.beSigned(JamesCantSign);

	NEW_LINE;
	std::cout << "WilliamCanSign will sign the unsigned PresidentialPardonForm" << std::endl;
	dany.beSigned(WilliamCanSign);

	NEW_LINE;
	std::cout << "CharlotteCantExecute will try to execute the already signed PresidentialPardonForm" << std::endl;
	dany.execute(CharlotteCantExecute);
	std::cout << "CharlotteCantExecute will try to execute PresidentialPardonForm from its member function" << std::endl;
	CharlotteCantExecute.executeForm(dany);

	NEW_LINE;
	std::cout << "IsabellaCanExecute will execute the already signed PresidentialPardonForm" << std::endl;
	dany.execute(IsabellaCanExecute);
	std::cout << "IsabellaCanExecute will try to execute PresidentialPardonForm from its member function" << std::endl;
	IsabellaCanExecute.executeForm(dany);

	NEW_LINE;
	return 0;
}
