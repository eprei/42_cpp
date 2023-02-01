#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

HumanB::~HumanB(void){}

void HumanB:: setWeapon(Weapon& ptr)
{
	this->_weapon = &ptr;
	return ;
}

void HumanB::attack(void) const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " still doesn't have a weapon assigned to attack" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
