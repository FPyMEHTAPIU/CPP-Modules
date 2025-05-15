#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(Animal const& animal) {
	*this = animal;
}

Animal::~Animal() {}

Animal& Animal::operator=(Animal const& animal) {
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}

void Animal::makeSound() const {}

std::string Animal::getType() const {
	return type;
}
