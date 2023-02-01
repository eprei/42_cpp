#ifndef ITER_HPP
# define ITER_HPP

# include <stddef.h>
# include <string>
# include <iosfwd>
# include <cstddef>
# include <iostream>

template<typename T>
void iter(T* tabPtr, std::size_t tabSize, void (*funPtr)(T const &))
{
	for (size_t i = 0; i < tabSize; i++)
	{
		funPtr(tabPtr[i]);
	}
	return;
}

template<typename U>
void printValue(U const & value)
{
	std::cout << "Value = " << value << std::endl;
	return;
}

template<typename R>
void addPlusOne(R & value)
{
	value = value + value;
	return;
}

#endif
