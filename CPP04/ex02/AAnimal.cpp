#include "AAnimal.hpp"

AAnimal::AAnimal() {}

AAnimal::AAnimal(AAnimal const& animal) {
	*this = animal;
}

AAnimal::~AAnimal() {}

AAnimal& AAnimal::operator=(AAnimal const& animal) {
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return type;
}
