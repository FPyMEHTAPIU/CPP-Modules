#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(WrongAnimal const& animal) {
	*this = animal;
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& animal) {
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {}

std::string WrongAnimal::getType() const {
	return type;
}
