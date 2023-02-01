#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

int RobotomyRequestForm::_nOfRobotomyCalls = 0;

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "String RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_isItSigned = rhs.getSigned();
	this->_target = rhs.getTarget();
	return *this;
}

std::string		RobotomyRequestForm::getTarget ( void ) const
{
	return _target;
}

void			RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		if (!_isItSigned)
			throw (RobotomyRequestForm::NoSignedException());
		if (executor.getGrade() > _gradeToExecute)
			throw (Form::GradeTooLowException());
		RobotomyRequestForm::_nOfRobotomyCalls += 1;
			std::cout << "**** drilling noises ****" << std::endl;
		if (RobotomyRequestForm::_nOfRobotomyCalls % 2 == 0)
			std::cout << _target << " has been successfully robotomised" << std::endl;
		else
			std::cout << "The operation has failed" << std::endl;
	}
	catch(RobotomyRequestForm::NoSignedException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch(Form::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	return ;
}

const char* RobotomyRequestForm::NoSignedException::what() const throw()
{
		return "Error: the form has not yet been signed";
}
