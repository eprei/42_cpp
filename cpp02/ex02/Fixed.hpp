#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

	public:

		Fixed( void );
		Fixed( const int i);
		Fixed( const float f);
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &		operator=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs );
		Fixed		operator-( Fixed const & rhs );
		Fixed		operator*( Fixed const & rhs );
		Fixed		operator/( Fixed const & rhs );

		bool	operator<( Fixed const & rhs ) const;
		bool	operator>( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed		operator++( void );
		Fixed		operator++( int );
		Fixed		operator--( void );
		Fixed		operator--( int );

		static Fixed &			min( Fixed & a, Fixed & b);
		static Fixed const &	min( Fixed const & a, Fixed const & b);
		static Fixed &			max( Fixed & a, Fixed & b);
		static Fixed const &	max( Fixed const & a, Fixed const & b);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:

		int					_value;
		static const int	_nOfBitsFraction;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
