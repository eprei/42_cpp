#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template<typename T>

typename T::iterator	easyfind(T &cont, int intToFind)
{
	typename T::iterator it;

	it =  find(cont.begin(), cont.end(), intToFind);
	if (it != cont.end())
		return (it);
	else
		throw std::out_of_range("Element not found");
}

#endif
