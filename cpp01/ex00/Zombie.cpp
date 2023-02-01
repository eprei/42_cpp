#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void){
	std::cout << "Zombie "<< this->_nom << " has been destroyed" << std::endl;
	return ;
}

void Zombie::announce( void ) const
{
	std::cout << this->_nom << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void Zombie::set_nom(std::string str)
{
	this->_nom = str;
	return ;
}

