#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < NUMBER_OF_IDEAS ; i++)
		_ideas[i] = "NO_IDEAS";
	return ;
}

Brain::Brain( Brain const & src )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called"<< std::endl;
	return ;
}

Brain &	Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < NUMBER_OF_IDEAS; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

std::string		Brain::getIdeas( int i ) const
{
	return ( this->_ideas[i] );
}

std::string const*	Brain::getIdeasAddress( int i ) const
{
	std::string const *ptr = &this->_ideas[i];
	return ( ptr );
}

void	Brain::setIdeas( int i, std::string str )
{
	if (i < NUMBER_OF_IDEAS && !str.empty())
		this->_ideas[i] = str;
	return;
}
