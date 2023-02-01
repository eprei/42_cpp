#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal( Animal const & src )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal &	Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "** Animal silence **" << std::endl;
	return ;
}
