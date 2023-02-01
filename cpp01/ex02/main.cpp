#include <string>
#include <iostream>

int main()
{
	std::string str =  "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "\nstr address =\t\t\t\t" << &str <<std::endl;
	std::cout << "Adresse stockée dans stringPTR =\t" << stringPTR << std::endl;
	std::cout << "Adresse stockée dans stringREF =\t" << &stringREF << std::endl;

	std::cout << "\nValeur de str =\t\t\t\t" << str << std::endl;
	std::cout << "Valeur pointée par stringPTR =\t\t" << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF =\t\t" << stringREF << std::endl;

	return 0;
}
