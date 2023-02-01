#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap string constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called. " << this->_name << " has been destroyed." << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void FragTrap::printStatus( void )
{
	std::cout << std::endl;
	std::cout << "FragTrap name\t:\t" << this->_name << std::endl;
	std::cout << "hit points\t:\t" << this->_hitPoints << std::endl;
	std::cout << "energy points\t:\t" << this->_energyPoints << std::endl;
	std::cout << "attack damage\t:\t" << this->_attackDamage << std::endl << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot speak. " << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " says: 'give me a High Five!'" << std::endl;
	return ;
}
