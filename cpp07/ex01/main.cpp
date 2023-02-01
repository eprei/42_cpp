#include "iter.hpp"

int main()
{
	int			tabInteger[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	char		tabCharacter[] = { '0' , '1' , '2' , '3' };
	std::string	tabString[] = { "one " , "two " , "three " , "four " , "five " };
	double		tabDoub[] = { 1.00 , 2.23 , 3.34 , 4.45 };
	float		tabFlo[] = { 10.01f , 20.02f , 30.03f , 40.04f };

	std::cout << std::endl << "______\t\tFunction 'printValue'\t\t_____" << std::endl;

	std::cout << "Function 'printValue' applied to the array 'tabInteger'" << std::endl << std::endl;
	iter(tabInteger, sizeof(tabInteger) / sizeof(int), printValue);

	std::cout <<std::endl << "Function 'printValue' applied to the array 'tabCharacter'" << std::endl << std::endl;
	iter(tabCharacter, sizeof(tabCharacter), printValue);

	std::cout <<std::endl << "Function 'printValue' applied to the array 'tabString'" << std::endl << std::endl;
	iter(tabString, sizeof(tabString) / sizeof(tabString[0]), printValue);

	std::cout <<std::endl << "Function 'printValue' applied to the array 'tabDoub'" << std::endl << std::endl;
	iter(tabDoub, sizeof(tabDoub) / sizeof(double), printValue);

	std::cout <<std::endl << "Function 'printValue' applied to the array 'tabFlo'" << std::endl << std::endl;
	iter(tabFlo, sizeof(tabFlo) / sizeof(float), printValue);

	return 0;
}
