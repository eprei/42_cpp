#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <string>

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);

		void	setWeapon(Weapon& ptr);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
