#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called. " << this->_name << " has been destroyed." << std::endl;
	return ;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void ScavTrap::attack( const std::string& target )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because he has 0 hit points. " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has not enough energy to attack" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std:: endl;
	return ;
}

void ScavTrap::printStatus( void )
{
	std::cout << std::endl;
	std::cout << "ScavTrap name\t:\t" << this->_name << std::endl;
	std::cout << "hit points\t:\t" << this->_hitPoints << std::endl;
	std::cout << "energy points\t:\t" << this->_energyPoints << std::endl;
	std::cout << "attack damage\t:\t" << this->_attackDamage << std::endl << std::endl;
	return ;
}

void ScavTrap::guardGate( void )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot enter in Gate keeper mode. " << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode." << std::endl;
	return ;
}
