#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );

		Cat &	operator=( Cat const & rhs );

		std::string		getType( void ) const;
		void			makeSound( void ) const;
		Brain*			getBrain( void ) const;

	protected:
		Brain* _brain;
};

#endif
