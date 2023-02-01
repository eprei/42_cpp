#include "Array.hpp"

#include <iostream>
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 5

class Awesome
{
	public:
		Awesome(void) : _n(424242) {}
		Awesome( int n ) : _n( n ) {}
		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

class ConstantAwesome
{
	public:
		ConstantAwesome(void) : _n(3000003) {}
		ConstantAwesome( int n ) : _n( n ) {}
		bool operator==( ConstantAwesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( ConstantAwesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( ConstantAwesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( ConstantAwesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( ConstantAwesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( ConstantAwesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		const int _n;
};
std::ostream & operator<<(std::ostream & o, const ConstantAwesome &a) { o << a.get_n(); return o; }


int main(int, char**)
{
	// TEST EMPTY ARRAY
	std::cout << std::endl << "__ TEST : EMPTY ARRAY" << std::endl << std::endl;
	Array<int> empty;
	try
	{
		std::cout << "Array<int> empty address = " << &empty << std::endl << "Attempt to access to empty[0] :\t" << empty[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// TEST SPECIFIC SIZE
	std::cout << std::endl << "__ TEST : SPECIFIC SIZE" << std::endl << std::endl;

	int * a = new int();
	std::cout << "a = " << a << std::endl;
	delete a;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout << "numbers[" << i << "]" << "\t=\t" << numbers[i] << std::endl;
		std::cout << "mirror[" << i << "]" << "\t=\t" << mirror[i] << std::endl;
	}

	// TEST CONSTRUCTEUR PAR COPIE
	std::cout << std::endl << "__ TEST : Constructeur par copie et opérateur d'assignation" << std::endl << std::endl;

	Array<int> tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "tmp[" << i << "]" << "\t\t=\t" << tmp[i] << std::endl;
		std::cout << "test[" << i << "]" << "\t\t=\t" << test[i] << std::endl;
	}
	std::cout << std::endl << "__ TEST : Modification of test to verify deep copy" << std::endl;

	for (int i = 0; i < MAX_VAL; i++) { test[i] = 42; }

	std::cout << std::endl << "Reprinting tmp and test to verify" << std::endl << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "tmp[" << i << "]" << "\t\t=\t" << tmp[i] << std::endl;
		std::cout << "test[" << i << "]" << "\t\t=\t" << test[i] << std::endl;

	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	// TEST ATTEMP TO ACCESS INVALID ARRAY NUMBER
	std::cout << std::endl << "__ TEST : Attempt to access invalid array numbers to check if exceptions are thrown" << std::endl << std::endl;

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// TEST ATTEMP TO WRITE AND READ FROM VALID ARRAY NUMBER
	std::cout << std::endl << "__ TEST : Attempt to access valid array numbers" << std::endl << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		int random = rand();
		numbers[i] = random;
		std::cout << "i = " << i << "\nrandom\t\t= " << random << std::endl << "numbers[" << i << "]" << "\t= " << numbers[i] << std::endl << std::endl;
	}
	delete [] mirror;

	// TEST ATTEMP TO READ FROM VALID CONST ARRAY NUMBER
	std::cout << std::endl << "__ TEST : Attempt to access valid const array numbers" << std::endl << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		Array<ConstantAwesome> constantAwsomes(MAX_VAL);
		std::cout << "constantAwsomes[" << i << "] = " << constantAwsomes[i] << std::endl;
	}
	std::cout << std::endl;

	// TEST COMPLEX TYPE
	Array<Awesome> complex(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "Complex[" << i << "]" << "\t\t=\t" << complex[i].get_n() << std::endl;

	// END OF TESTS

	return 0;
}
