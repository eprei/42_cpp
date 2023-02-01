#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <exception>
# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat{

	public:

		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		virtual ~Bureaucrat( void );

		Bureaucrat &	operator=( Bureaucrat const & rhs );

		std::string		getName( void ) const;
		int				getGrade( void ) const;

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

		void 	increaseDegree( void );
		void 	decreaseDegree( void );

	protected:

		const std::string	_name;
		int					_grade;
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
