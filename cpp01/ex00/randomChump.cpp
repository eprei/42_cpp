#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie newZombieRandom;

	newZombieRandom.set_nom(name);
	newZombieRandom.announce();
	return ;
}
