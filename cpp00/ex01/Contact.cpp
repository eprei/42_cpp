#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	// std::cout << "contact has been created" << std:: endl;
	// Contact::_nb_inst += 1;
	// std::cout << "instance number" << Contact::get_nb_inst() << std::endl;
	return ;
}

Contact::~Contact(void)
{
//	std::cout << "contact has been destroyed" << std:: endl;
	return ;
}

int		Contact::_nb_inst = 0;

int		Contact::get_nb_inst(void)
{
	return Contact::_nb_inst;
}

void	Contact::add_nb_inst(void)
{
	Contact::_nb_inst += 1;
	return ;
}

std::string	Contact::get_first_name(void) const
{
	return this->_first_name;
}

std::string	Contact::get_last_name(void) const
{
	return this->_last_name;
}

std::string	Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string	Contact::get_phone_number(void) const
{
	return this->_phone_number;
}

std::string	Contact::get_darkest_secret(void) const
{
	return this->_darkest_secret;
}

void		Contact::set_first_name(std::string str)
{
	this->_first_name = str;
	return ;
}

void		Contact::set_last_name(std::string str)
{
	this->_last_name = str;
	return ;
}

void		Contact::set_nickname(std::string str)
{
	this->_nickname = str;
	return ;
}

void		Contact::set_phone_number(std::string str)
{
	this->_phone_number = str;
	return ;
}

void		Contact::set_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
	return ;
}

void		Contact::print_contact(void) const
{
	std::cout << std::setw(10);
	std::cout << this->_index << " | ";

	std::string cuted_string = this->_first_name.substr(0, 10);
	if (this->_first_name.length() >= 10)
		cuted_string.replace(9, 1, ".");
	std::cout << std::setw(10);
	std::cout << cuted_string << " | ";

	std::string cuted_string2 = this->_last_name.substr(0, 10);
	if (this->_last_name.length() >= 10)
		cuted_string2.replace(9, 1, ".");
	std::cout << std::setw(10);
	std::cout << cuted_string2 << " | ";

	std::string cuted_string3 = this->_nickname.substr(0, 10);
	if (this->_nickname.length() >= 10)
		cuted_string3.replace(9, 1, ".");
	std::cout << std::setw(10);
	std::cout << cuted_string3;

	std::cout << std::endl;

	return ;
}

void		Contact::print_full_contact(void) const
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	return ;
}

int			Contact::get_index(void) const
{
	return this->_index;
}

void		Contact::set_index(int i)
{
	this->_index = i;
	return ;
}
