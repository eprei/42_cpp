#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>

class Span
{
	public:

		Span( unsigned int N);
		Span( Span const & src);
		~Span( void );

		Span & operator=( Span const & rhs);

		unsigned int		getMaxNum( void ) const;
		std::vector<int>	getVec( void ) const;
		void				addNumber( int number );
		template <class T>
		void				addRangeOfNumbers(const T & start , const T & end);
		unsigned int		shortestSpan( void ) const;
		unsigned int		longestSpan( void ) const;

		class notEnoughNumbers: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class notSpace: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		Span( void );
		unsigned int		_maxNum;
		unsigned int		_initialN;
		std::vector<int>	_vec;
};

template <class T>
void				Span::addRangeOfNumbers(const T & start, const T & end)
	{
		if ( static_cast<unsigned int>(std::distance(start, end)) > _maxNum)
		{
			throw (notSpace());
		}
		std::copy(start, end, std::back_inserter(_vec));
		_maxNum -= std::distance(start, end);
		return ;
	}

std::ostream	& operator<<(std::ostream & o, Span const & src);

#endif
