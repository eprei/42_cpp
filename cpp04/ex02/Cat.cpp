#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void )
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
	return ;
}

Cat::Cat( Cat const & src ) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = src;
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called"<< std::endl;
	delete _brain;
	return ;
}

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
			this->_brain->setIdeas( i, rhs._brain->getIdeas(i));
		this->_type = rhs._type;
	}
	return *this;
}

std::string	Cat::getType( void ) const
{
	return (this->_type);
}

Brain*	Cat::getBrain( void ) const
{
	return ( _brain );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat says: meow !" << std::endl;
	return ;
}
