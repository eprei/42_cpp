#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called. "<< std::endl;
	return ;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	WrongCat::getType( void ) const
{
	return (this->_type);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat says: meow !" << std::endl;
	return ;
}
