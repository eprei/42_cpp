#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog( void )
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	return ;
}

Dog::Dog( Dog const & src ) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
	return ;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called"<< std::endl;
	delete _brain;
	return ;
}

Dog &	Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
			this->_brain->setIdeas( i, rhs._brain->getIdeas(i));
		this->_type = rhs._type;
	}
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

Brain*	Dog::getBrain( void ) const
{
	return ( _brain );
}
