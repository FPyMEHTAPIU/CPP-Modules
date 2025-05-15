#include "Cat.hpp"

Cat::Cat(): Animal() {
	type = "Cat";
}

Cat::Cat(Cat const& cat): Animal(cat) {
	*this = cat;
}

Cat::~Cat() {}

Cat& Cat::operator=(Cat const& cat) {
	if (this != &cat) {
		type = cat.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meeeoww :3" << std::endl;
}