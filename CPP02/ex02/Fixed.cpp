#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

Fixed::Fixed(): _value(0) {}

Fixed::Fixed(const int point) {
	_value = point << _fractionBits;
}

Fixed::Fixed(const float point) {
	_value = roundf(point * (1 << _fractionBits));
}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
	if (this != &fixed) {
		_value = fixed._value;
	}
	return *this;
}

Fixed::~Fixed() {}

std::ostream& operator<<(std::ostream &out, Fixed const& fixed) {
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat( void ) const {
	return (float) _value / (1 << _fractionBits);
}

int Fixed::toInt( void ) const {
	return _value >> _fractionBits;
}

bool Fixed::operator>(Fixed const& fixed) const {
	return (_value > fixed._value);
}

bool Fixed::operator<(Fixed const& fixed) const {
	return (_value < fixed._value);
}

bool Fixed::operator>=(Fixed const& fixed) const {
	return (_value >= fixed._value);
}

bool Fixed::operator<=(Fixed const& fixed) const {
	return (_value <= fixed._value);
}

bool Fixed::operator==(Fixed const& fixed) const {
	return (_value == fixed._value);
}

bool Fixed::operator!=(Fixed const& fixed) const {
	return (_value != fixed._value);
}

Fixed Fixed::operator+(Fixed const& fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed const& fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed const& fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed const& fixed) const {
	if (fixed._value == 0) {
		std::cerr << "Warning: Division by zero!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++() {
	++_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_value;
	return temp;
}

Fixed& Fixed::operator--() {
	--_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_value;
	return temp;
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
	return n1._value < n2._value ? n1 : n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
	return n1._value < n2._value ? n1 : n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	return n1._value > n2._value ? n1 : n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
	return n1._value > n2._value ? n1 : n2;
}