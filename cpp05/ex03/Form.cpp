#include "Form.hpp"
#include <iostream>

Form::Form( void ) : _name("[ unnamed form ]"), _isItSigned(false),
_gradeToSigne(1), _gradeToExecute(1)
{
	// std::cout << "Default Form constructor called" << std::endl;
	return ;
}

Form::Form( Form const & src ) : _name(src.getName()), _isItSigned(src.getSigned()),
_gradeToSigne(src.getGradeToSigne()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Copy Form constructor called" << std::endl;
	*this = src;
	return ;
}

Form::Form( std::string name, int gradeToSigne, int gradeToExecute) : _name(name), _isItSigned(false),
_gradeToSigne(gradeToSigne),  _gradeToExecute(gradeToExecute)
{
	// std::cout << "Form constructor called. [ name ] [ gradeToSigne ] [ gradeToExecute ]" << std::endl;
	try
	{
		if ( gradeToSigne < MAX_GRADE || gradeToExecute < MAX_GRADE)
			throw (Form::GradeTooHighException());
		else if ( gradeToSigne > MIN_GRADE || gradeToExecute > MIN_GRADE)
			throw (Form::GradeTooLowException());
		// std::cout << "The form has been successfully created" << std::endl;
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow exception happened" << std::endl;
	}
	return ;
}

Form::~Form(void)
{
	// std::cout << "Destructor Form called" << std::endl;
	return ;
}

Form &	Form::operator=( Form const & rhs )
{
	std::cout << "Copy assignment operator Form called" << std::endl;
	if (this != &rhs)
		this->_isItSigned = rhs._isItSigned;
	return *this;
}

std::string	Form::getName( void ) const
{
	return _name;
}

bool		Form::getSigned( void ) const
{
	return _isItSigned;
}

int	Form::getGradeToSigne( void ) const
{
	return _gradeToSigne;
}

int	Form::getGradeToExecute( void ) const
{
	return _gradeToExecute;
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	std::cout << std::boolalpha;
	o << "Name :\t\t\t"<< rhs.getName() << std::endl;
	o << "Is it signed :\t\t"<< rhs.getSigned() << std::endl;
	o << "Grade to signe :\t"<< rhs.getGradeToSigne() << std::endl;
	o << "Grade to execute :\t"<< rhs.getGradeToExecute() << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
		return "Invalid form. The grade you are trying to assign is too high. The grade of a Bureaucrat should be between 1 and 150.";
}

const char* Form::GradeTooLowException::what() const throw()
{
		return "Error: The grade is too low.";
}

void		Form::beSigned( const Bureaucrat& certifier )
{
	try
	{
		if ( certifier.getGrade() > this->_gradeToSigne)
			throw (Form::GradeTooLowException());
		_isItSigned = true;
		std::cout << certifier.getName() << " has signed the form : " << this->_name << std::endl;
	}
	catch(Form::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	return ;
}

void		Form::changeSigneStatusToTrue ( void )
{
	_isItSigned = true;
	return;
}
