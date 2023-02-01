#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>


int main()
{
	// TEST WITH VECTORS
	std::cout << std::endl << "________\t\tTEST WITH VECTORS\t\t________" << std::endl << std::endl;

	std::vector<int>			myVector;
	std::vector<int>::iterator	itVecInt;

	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);
	myVector.push_back(40);

	for (int i = 0; i < 4; i++)
		std::cout << "myVector[" << i << "] = " << myVector[i] << "\taddress = " << &myVector[i] << std::endl;
	std::cout  << std::endl;
	try
	{
		itVecInt = easyfind(myVector, 20);
		std::cout << "The result of easyfind(myVector, 20) is\titVecInt = " << *itVecInt << "\taddress = " << &(*itVecInt) << std::endl;
		itVecInt = easyfind(myVector, 40);
		std::cout << "The result of easyfind(myVector, 40) is\titVecInt = " << *itVecInt << "\taddress = " << &(*itVecInt) << std::endl;
		itVecInt = easyfind(myVector, 600);
		std::cout << "The result of easyfind(myVector, 600) is\titVecInt = " << *itVecInt << "\taddress = " << &(*itVecInt) << std::endl;
	}
	catch (const std::out_of_range& e) { std::cerr << "Exception caught: " << e.what() << '\n'; }

	// TEST WITH LIST
	std::cout << std::endl << "________\t\tTEST WITH LIST\t\t________" << std::endl << std::endl;

	std::list<int>				mylist;
	std::list<int>::iterator	itListInt;
	std::list<int>::iterator itTmp = mylist.begin();

	mylist.push_back(555);
	mylist.push_back(666);
	mylist.push_back(777);
	mylist.push_back(888);

	for (std::size_t i = 0; i < mylist.size(); i++)
	{
		itTmp++;
		std::cout << "mylist[" << i << "] = " << *itTmp << "\taddress = " << &(*itTmp) << std::endl;
	}
	std::cout  << std::endl;

	try
	{
		itListInt = easyfind(mylist, 555);
		std::cout << "The result of easyfind(mylist, 555) is\titListInt = " << *itListInt << "\taddress = " << &(*itListInt) << std::endl;
		itListInt = easyfind(mylist, 888);
		std::cout << "The result of easyfind(mylist, 888) is\titListInt = " << *itListInt << "\taddress = " << &(*itListInt) << std::endl;
		itListInt = easyfind(mylist, 999);
		std::cout << "The result of easyfind(mylist, 999) is\titListInt = " << *itListInt << "\taddress = " << &(*itListInt) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	return 0;
}
