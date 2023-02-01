#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap tito("Tito");
	FragTrap mario("Mario");
	FragTrap arthur("Arthur");
	FragTrap clonArthur(arthur);

	clonArthur.printStatus();

	tito.printStatus();
	tito.attack("Leonidas");
	tito.printStatus();
	tito.takeDamage(5);
	tito.printStatus();
	tito.beRepaired(40);
	tito.printStatus();

	mario.printStatus();
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.printStatus();
	mario.highFivesGuys();

	arthur.printStatus();
	arthur.takeDamage(50);
	arthur.takeDamage(50);
	arthur.beRepaired(40);
	arthur.attack("Leonidas");
	arthur.highFivesGuys();
	arthur.printStatus();

	return (0);
}
