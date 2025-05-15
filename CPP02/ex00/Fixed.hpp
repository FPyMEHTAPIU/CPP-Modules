#pragma once
#include <iostream>

class Fixed {
	private:
		int _fixedPoint;
		static const int _fractionBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed& operator=(Fixed const& fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};