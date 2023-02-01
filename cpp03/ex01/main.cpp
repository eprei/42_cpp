#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap tito("Tito");
	ScavTrap mario("Mario");
	ScavTrap arthur("Arthur");
	ScavTrap clonArthur(arthur);

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
	mario.guardGate();

	arthur.printStatus();
	arthur.takeDamage(50);
	arthur.takeDamage(50);
	arthur.beRepaired(40);
	arthur.attack("Leonidas");
	arthur.guardGate();
	arthur.printStatus();

	return (0);
}
