#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fractionBits;

	public:
		Fixed();
		Fixed(const int point);
		Fixed(const float point);
		Fixed(const Fixed& fixed);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed& operator=(Fixed const& fixed);
		bool operator>(Fixed const& fixed) const;
		bool operator<(Fixed const& fixed) const;
		bool operator>=(Fixed const& fixed) const;
		bool operator<=(Fixed const& fixed) const;
		bool operator==(Fixed const& fixed) const;
		bool operator!=(Fixed const& fixed) const;

		Fixed operator+(Fixed const& fixed) const;
		Fixed operator-(Fixed const& fixed) const;
		Fixed operator*(Fixed const& fixed) const;
		Fixed operator/(Fixed const& fixed) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& n1, Fixed& n2);
		static const Fixed& min(const Fixed& n1, const Fixed& n2);
		static Fixed& max(Fixed& n1, Fixed& n2);
		static const Fixed& max(const Fixed& n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream &out, Fixed const& fixed);