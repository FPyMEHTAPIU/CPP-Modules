#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const& animal) {
	*this = animal;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const& animal) {
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Some unknown terrifying sound" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
