#include "Zombie.hpp"
#include <string>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main()
{
	Zombie	Ugo;
	Zombie*	Peter;

	Ugo.set_nom("Ugo");
	Ugo.announce();

	Peter = newZombie("Peter");
	Peter->announce();

	randomChump("Random Zombie");

	delete Peter;

	return (0);
}
