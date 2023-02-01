#include "ClapTrap.hpp"

int main()
{
	ClapTrap tito("Tito");
	ClapTrap mario("Mario");
	ClapTrap arthur("Arthur");
	ClapTrap clonArthur(arthur);

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
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.attack("Leonidas");
	mario.printStatus();

	arthur.printStatus();
	arthur.takeDamage(5);
	arthur.takeDamage(5);
	arthur.beRepaired(40);
	arthur.attack("Leonidas");
	arthur.printStatus();

	return (0);
}
