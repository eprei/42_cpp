#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm( void );

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

		class NoSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void			execute( Bureaucrat const & executor ) const ;

		std::string		getTarget ( void ) const;

	private:

		std::string _target;
};

#endif
