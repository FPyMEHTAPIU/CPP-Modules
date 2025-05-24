#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	type = "WrongCat";
	std::cout << type << " constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& cat): WrongAnimal(cat) {
	*this = cat;
}

WrongCat::~WrongCat() {
	std::cout << type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& cat) {
	if (this != &cat) {
		type = cat.type;
	}
	return *this;
}