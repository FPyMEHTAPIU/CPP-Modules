#pragma once
#include <iostream>

class Fixed {
	private:
		int _fixedPoint;
		static const int _fractionBits;

	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(Fixed const& fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};