#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap String constructor called" << std::endl;
	return ;
}


ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called. " << this->_name << " has been destroyed." << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void ClapTrap::attack( const std::string& target )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has 0 hit points. " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy to attack" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std:: endl;
	return ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has 0 hit points. " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damage points" << std:: endl;
	return ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has 0 hit points. " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has not enough energy to repair itself" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " hit points" << std:: endl;
	return ;
}

void ClapTrap::printStatus( void )
{
	std::cout << std::endl;
	std::cout << "ClapTrap name\t:\t" << this->_name << std::endl;
	std::cout << "hit points\t:\t" << this->_hitPoints << std::endl;
	std::cout << "energy points\t:\t" << this->_energyPoints << std::endl;
	std::cout << "attack damage\t:\t" << this->_attackDamage << std::endl << std::endl;
	return ;
}
