#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "String PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_isItSigned = rhs.getSigned();
	this->_target = rhs.getTarget();
	return *this;
}

std::string		PresidentialPardonForm::getTarget ( void ) const
{
	return _target;
}

void			PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		if (!_isItSigned)
			throw (PresidentialPardonForm::NoSignedException());
		if (executor.getGrade() > _gradeToExecute)
			throw (Form::GradeTooLowException());
		std::cout << _target << " was forgiven by Zaphod Beeblebrox" << std::endl;
	}
	catch(PresidentialPardonForm::NoSignedException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch(Form::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	return ;
}

const char* PresidentialPardonForm::NoSignedException::what() const throw()
{
		return "Error: the form has not yet been signed";
}
