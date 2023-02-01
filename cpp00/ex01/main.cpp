#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

int main()
{
	PhoneBook phone;

	phone.set_exit_status(0);
	while (phone.get_exit_status() == false)
		phone.start_phone();
	return (0);
}
