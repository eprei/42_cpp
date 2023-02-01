#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* groupOfZombies;

	if (N < 0 || name.length() == 0)
		return (NULL);
	groupOfZombies = new Zombie[N];
	while (N > 0)
		groupOfZombies[--N].set_nom(name);
	return groupOfZombies;
}
