#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern
{
	public:

		Intern( void );
		Intern( Intern const & src );
		~Intern( void );

		Intern &	operator=( Intern const & rhs );

		Form* 		makeForm( std::string nomDuFormulaire, std::string cible ) const;
};

#endif
