#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) :Form( "ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "String ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form( "ShrubberyCreationForm", 145, 137)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_isItSigned = rhs.getSigned();
	this->_target = rhs.getTarget();
	return *this;
}

std::string		ShrubberyCreationForm::getTarget ( void ) const
{
	return _target;
}

void			ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	std::ofstream	ofs;
	std::string		outputFileName;

	try
	{
		if (!_isItSigned)
			throw (ShrubberyCreationForm::NoSignedException());
		if (executor.getGrade() > _gradeToExecute)
			throw (Form::GradeTooLowException());
		outputFileName = _target;
		outputFileName.append("_shrubbery");
		ofs.open(outputFileName.data());
		if (!ofs.is_open())
			throw (ShrubberyCreationForm::OpeningFileException());
		ofs << "               ,@@@@@@@," << std::endl;
		ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl;
		ofs << "    ,&'%'%&%&&%,@@@@@/@@@@@@,8888'\'88/8o" << std::endl;
		ofs << "   ,%&'\'%&&%&&%,@@@'\'@@@/@@@88'\'88888/88'" << std::endl;
		ofs << "   %&&%&%&/%&&%@@'\'@@/ /@@@88888'\'88888'" << std::endl;
		ofs << "   %&&%/ %&'%'%&&@@'\' V /@@' `88'\'8 `/88'" << std::endl;
		ofs << "   `&%'\' ` /%&'    |.|        '\' '|8'" << std::endl;
		ofs << "       |o|        | |         | |" << std::endl;
		ofs << "       |.|        | |         | |" << std::endl;
		ofs << "    \\/ ._'\'//_/__/  ,'\'_//__\\/.  '\'_//__/_ " << std::endl;
		ofs.close();
		std::cout << "ShrubberyCreationForm successfully executed: " << outputFileName << "has been created" << std::endl;
	}
	catch(ShrubberyCreationForm::NoSignedException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch(Form::GradeTooLowException& r)
	{
		std::cout << r.what() << std::endl;
	}
	catch(ShrubberyCreationForm::OpeningFileException& o)
	{
		std::cout << o.what() << std::endl;
	}
	return ;
}

const char* ShrubberyCreationForm::NoSignedException::what() const throw()
{
		return "Error: the form has not yet been signed";
}

const char* ShrubberyCreationForm::OpeningFileException::what() const throw()
{
		return "Error: the file could not be opened";
}
