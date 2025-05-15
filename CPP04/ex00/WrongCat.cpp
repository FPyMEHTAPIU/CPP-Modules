#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& cat): WrongAnimal(cat) {
	*this = cat;
}

WrongCat::~WrongCat() {}

WrongCat& WrongCat::operator=(WrongCat const& cat) {
	if (this != &cat) {
		type = cat.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Ƹ̵̡Ӝ̵̨̄Ʒ Meow?" << std::endl;
}