#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fractionBits;

	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int point);
		Fixed(const float point);
		~Fixed();

		Fixed& operator=(Fixed const& fixed);

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const& fixed);