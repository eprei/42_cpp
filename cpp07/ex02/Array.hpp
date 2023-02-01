#ifndef ARRAY_HPP
# define ARRAY_HPP

# include	<iostream>
#include	<fstream>

template<typename T>
class Array
{
	public:

		Array<T>( void ): _tab(NULL), _size(0){};
		Array<T>( unsigned int n ): _size(n)
		{
			if (n > 0)
				_tab = new T[_size];
		};
		Array<T>( Array<T> const & src )
		{
			*this = src;
		};
		~Array<T>( void )
		{
			if(_size > 0)
				delete [] _tab;
		};
		Array &	operator=( Array const & rhs )
		{
			if (this != &rhs)
			{
				this->_size = rhs._size;
				if (this->_size > 0)
				{
					this->_tab = new T[_size];
					for (unsigned int i = 0; i < this->_size ; i++)
						this->_tab[i] = rhs._tab[i];
				}
			}
			return *this;
		};
		T&	operator[]( unsigned int i )
		{
			if (i > _size -1 || _tab == NULL)
					throw (NonExistentArrayNumberException());
			return _tab[i];
		};

		T&	operator[]( unsigned int const i ) const
		{
			if (i > _size -1 || _tab == NULL)
					throw (NonExistentArrayNumberException());
			return _tab[i];
		};

		unsigned int 	size( void ) const
		{
			return _size;
		};

		class NonExistentArrayNumberException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Non-existent array number\n";
				}
		};

	private:

		T* 				_tab;
		unsigned int	_size;
};

#endif
