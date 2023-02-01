#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	return ;
}

Dog::Dog( Dog const & src ) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called"<< std::endl;
	return ;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	Dog::getType( void ) const
{
	return (this->_type);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog says: woof !" << std::endl;
	return ;
}
