#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& animal) {
	*this = animal;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal destructor called" << std::endl;
}

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
