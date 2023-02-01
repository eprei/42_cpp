#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): _name(name)
{
	std::cout << "Bureaucrat name & grade constructor called" << std::endl;
	try
	{
		if ( grade < MAX_GRADE)
			throw (Bureaucrat::GradeTooHighException());
		else if ( grade > MIN_GRADE)
			throw (Bureaucrat::GradeTooLowException());
		_grade = grade;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow exception happened" << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
		return "The grade you are trying to assign is too high. The grade of a Bureaucrat should be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
		return "The grade you are trying to assign is too low. The grade of a Bureaucrat should be between 1 and 150.";
}

void 	Bureaucrat::increaseDegree( void )
{
	std::cout << "Increase Degree function called" << std::endl;
	try
	{
		if ( _grade - 1 < MAX_GRADE)
			throw (Bureaucrat::GradeTooHighException());
		_grade -= 1;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow exception happened" << std::endl;
	}
	return;
}

void 	Bureaucrat::decreaseDegree( void )
{
	std::cout << "Decrease Degree function called" << std::endl;
	try
	{
		if ( _grade + 1 > MIN_GRADE)
			throw (Bureaucrat::GradeTooLowException());
		_grade += 1;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow exception happened" << std::endl;
	}
	return;
}
