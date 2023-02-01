#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define NUMBER_OF_IDEAS 100
# define NEW_LINE std::cout << std::endl

class Brain{

	public:

		Brain( void );
		Brain( Brain const & src );
		~Brain( void );

		Brain &	operator=( Brain const & rhs );

		std::string			getIdeas( int i ) const;
		void				setIdeas( int i, std::string str );
		std::string const*	getIdeasAddress( int i ) const;

	protected:

		std::string	_ideas[NUMBER_OF_IDEAS];
};

#endif
