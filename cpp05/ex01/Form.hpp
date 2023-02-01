#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150
# define NEW_LINE std::cout << std::endl

class Bureaucrat;

class Form{

	public:

		Form( void );
		Form( Form const & src );
		Form( std::string name, int gradeToSigne, int gradeToExecute);
		virtual ~Form( void );

		Form &	operator=( Form const & rhs );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeToSigne( void ) const;
		int			getGradeToExecute( void ) const ;
		void		beSigned( const Bureaucrat& certifier );
		void		changeSigneStatusToTrue ( void );

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		const std::string	_name;
		bool				_isItSigned;
		const int			_gradeToSigne;
		const int			_gradeToExecute;

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif
