#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int	numOfZombies = 42;
	Zombie*	groupOfZombies = zombieHorde(numOfZombies, "Leonidas");

	if (groupOfZombies == NULL)
		return 1 ;
	for (int i = 0; i < numOfZombies; i++)
		groupOfZombies[i].announce();
	delete [] groupOfZombies;
	return 0;
}
