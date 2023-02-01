#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span( void ){};

Span::Span( unsigned int N ): _maxNum( N ) , _initialN( N ) {};

Span::Span( Span const & src)
{
	*this = src;
	return ;
};

Span::~Span( void ){};

Span & Span::operator=( Span const & rhs)
{
	if (this != &rhs)
	{
		_maxNum = rhs.getMaxNum();
		_vec = rhs.getVec();
	}
	return *this;
}

unsigned int		Span::getMaxNum( void ) const { return _maxNum; }

std::vector<int>	Span::getVec( void ) const {return _vec; }

void	Span::addNumber( int number )
{
	if ( _maxNum == 0)
		throw (notSpace());
	_vec.push_back(number);
	_maxNum--;
	return;
}

unsigned int	Span::shortestSpan( void ) const
{
	unsigned int		minDiff = UINT_MAX;
	std::vector<int>	vecSorted = _vec;

	std::sort(vecSorted.begin(), vecSorted.end());

	if ( _initialN - _maxNum < 2 )
			throw (notEnoughNumbers());
	for ( unsigned long long int i = 0; i < _vec.size() - 1 ; i++)
	{
		if (static_cast<unsigned int>(_vec[i + 1] - _vec[i]) < minDiff)
			minDiff = _vec[i + 1] - _vec[i];
	}
	return minDiff;
}

unsigned int	Span::longestSpan( void ) const
{
	if ( _initialN - _maxNum < 2 )
			throw (notEnoughNumbers());
	return ((*std::max_element(_vec.begin(), _vec.end())) - (*std::min_element(_vec.begin(), _vec.end())));
}


const char*	Span::notEnoughNumbers::what() const throw()
{
	return "There are not enough numbers stored to calculate a distance";
}

const char*	Span::notSpace::what() const throw()
{
	return "Impossible to add the new element. Span has already assigned the maximum number of possible elements";
}

std::ostream &	operator<<( std::ostream & o, Span const & src)
{
	if(src.getVec().size() == 0)
		o << "\t\tThis Span it's empty" << std::endl;
	else
	{
		for (unsigned long int i = 0; i < src.getVec().size(); i++)
			o << "vector[" << i << "] = " << src.getVec()[i] << std::endl;
	}
	return o;
}
