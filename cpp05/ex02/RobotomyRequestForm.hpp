#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm( void );

		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

		class NoSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void			execute( Bureaucrat const & executor ) const ;

		std::string		getTarget ( void ) const;

	private:

		std::string _target;
		static int	_nOfRobotomyCalls;
};

#endif
