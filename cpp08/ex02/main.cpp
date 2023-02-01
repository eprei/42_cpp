#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		// TEST WITH MUTANSTACK
		std::cout << std::endl << "TEST WITH MUTANTSTACK" << std::endl << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size = " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << std::endl << "Printing with begin iterator" << std::endl;
		while (it != ite)
		{
			std::cout << "*iterator\t= " << *it << std::endl;
			*it *= 10;
			std::cout << "*iterator /10\t= " << *it << std::endl;
			++it;
		}

		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		++rit;
		--rit;
		std::cout << std::endl << "Printing with reverse begin iterator" << std::endl;
		while (rit != rite)
		{
			std::cout << "*reverse iterator\t= " << *rit << std::endl;
			*rit /= 10;
			std::cout << "*reverse iterator / 10\t= " << *rit << std::endl;
			++rit;
		}
// START

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << std::endl << "Printing with begin iterator" << std::endl;
		while (it != ite)
		{
			std::cout << "*iterator\t= " << *it << std::endl;
			*it *= 10;
			std::cout << "*iterator /10\t= " << *it << std::endl;
			++it;
		}

		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		++rit;
		--rit;
		std::cout << std::endl << "Printing with reverse begin iterator" << std::endl;
		while (rit != rite)
		{
			std::cout << "*reverse iterator\t= " << *rit << std::endl;
			*rit /= 10;
			std::cout << "*reverse iterator / 10\t= " << *rit << std::endl;
			++rit;
		}
// END
		std::stack<int> s(mstack);

	}
	else
	{
		// TEST WITH LIST
		std::cout << std::endl << "TEST WITH LIST" << std::endl << std::endl ;
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout << "size = " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		std::cout << std::endl << "Printing with begin iterator" << std::endl;
		while (it != ite)
		{
			std::cout << "*iterator\t= " << *it << std::endl;
			*it *= 10;
			std::cout << "*iterator /10\t= " << *it << std::endl;
			++it;
		}

		std::list<int>::reverse_iterator rit = mlist.rbegin();
		std::list<int>::reverse_iterator rite = mlist.rend();

		++rit;
		--rit;
		std::cout << std::endl << "Printing with reverse begin iterator" << std::endl;
		while (rit != rite)
		{
			std::cout << "*reverse iterator\t= " << *rit << std::endl;
			*rit /= 10;
			std::cout << "*reverse iterator / 10\t= " << *rit << std::endl;
			++rit;
		}

		std::list<int> s(mlist);

	}
	return 0;
}
