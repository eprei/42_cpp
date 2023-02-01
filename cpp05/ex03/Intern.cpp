#include "Intern.hpp"
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Default Intern constructor called" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Destructor Intern called" << std::endl;
	return ;
}

Intern::Intern( Intern const & src )
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = src;
	return ;
}

Intern &	Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	std::cout << "Copy Intern assignment operator called" << std::endl;
	return *this;
}

Form* 		Intern::makeForm( std::string nomDuFormulaire, std::string cible ) const
{
	Form*		ptr = NULL;
	std::string	str[3] = { "presidential pardon" , "robotomy request" , "shrubbery creation" };
	Form*		array[3] = { new PresidentialPardonForm( cible ) , new RobotomyRequestForm( cible ), new ShrubberyCreationForm( cible )};
	int			index = -1;

	for (int i = 0; i < 3; i++)
	{
		if (nomDuFormulaire.compare(str[i]) == 0)
		{
			index = i;
			ptr = array[index];
			std::cout << "Intern creates: " << nomDuFormulaire << std::endl;
		}
		else
			delete array[i];
	}
	if (index == -1)
		std::cout << "There is no form with the name: " << nomDuFormulaire << std::endl;
	return (ptr);
}
