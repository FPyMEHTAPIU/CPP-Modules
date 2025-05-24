#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& animal) {
	*this = animal;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& animal) {
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return type;
}
