#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <iomanip>

class Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void	announce( void ) const;
		void	set_nom(std::string str);

	private:

		std::string _nom;
};

#endif
