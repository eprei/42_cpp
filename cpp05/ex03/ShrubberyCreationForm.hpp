#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

		class NoSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class OpeningFileException: public std::exception
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
