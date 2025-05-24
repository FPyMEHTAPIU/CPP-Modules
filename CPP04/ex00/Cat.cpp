#include "Cat.hpp"

Cat::Cat(): Animal() {
	type = "Cat";
	std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(Cat const& cat): Animal(cat) {
	*this = cat;
}

Cat::~Cat() {
	std::cout << type << " destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const& cat) {
	if (this != &cat) {
		type = cat.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "=^..^= Meeeoww" << std::endl;
}