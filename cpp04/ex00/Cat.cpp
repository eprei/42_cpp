#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	return ;
}

Cat::Cat( Cat const & src ) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called"<< std::endl;
	return ;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	Cat::getType( void ) const
{
	return (this->_type);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat says: meow !" << std::endl;
	return ;
}
