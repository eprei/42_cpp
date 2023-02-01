#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class	Weapon
{
	public:

		Weapon(void);
		~Weapon(void);
		Weapon(std::string weapon);

		const std::string&	getType(void) const;
		void				setType(std::string str);

	private:

		std::string	_type;
};

#endif
