#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void){}

Weapon::~Weapon(void){}

Weapon::Weapon(std::string weapon): _type(weapon){}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string str)
{
	this->_type = str;
	return ;
}
