#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack<T>( void ) {}
		MutantStack<T>( MutantStack const & src) { *this = src; }
		~MutantStack<T>( void ){}

		MutantStack & operator=( MutantStack const & rhs)
		{
			if (*this != rhs)
				*this = rhs;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin() { return (this->c.cbegin()); }
		const_iterator cend() { return (this->c.cend()); }

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() { return (this->c.crbegin()); }
		const_reverse_iterator crend() { return (this->c.crend()); }
};

#endif
