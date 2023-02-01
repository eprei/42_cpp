#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl(void){}

Harl::~Harl(void){}

void Harl::complain(std::string level)
{
	void		(Harl::*p[4])(void) = { &Harl::debug , &Harl::info , &Harl::warning , &Harl::error };
	std::string	str[4] = { "debug" , "info" , "warning",  "error"};

	for (int i = 0; i < 4; i++)
	{
		if (str[i].compare(level) == 0)
			(this->*p[i])();
	}
	return ;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
	return ;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	return ;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}
