#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

template<typename T, typename U>
void swap(T & x, U & y)
{
	U tempU = y;

	y = x;
	x = tempU;

	return;
}

template<typename T>
T const & max(T const & x, T const & y){ return (x > y? x : y);}

template<typename T>
T const & min(T const & x, T const & y){ return (x < y? x : y);}

#endif
