#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int point) {
	std::cout << "Int constructor called" << std::endl;
	_value = point << _fractionBits;
}

Fixed::Fixed(const float point) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(point * (1 << _fractionBits));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		_value = fixed._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

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