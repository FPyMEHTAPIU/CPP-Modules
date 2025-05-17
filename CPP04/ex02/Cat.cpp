#include "Cat.hpp"

Cat::Cat(): AAnimal() {
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat with a brain constructor" << std::endl;
}

Cat::Cat(Cat const& cat): AAnimal(cat) {
	_brain = new Brain(*cat._brain);
	*this = cat;
}

Cat::~Cat() {
	std::cout << "Cat with a brain destructor" << std::endl;
	delete _brain;
}

Cat& Cat::operator=(Cat const& cat) {
	if (this != &cat) {
		AAnimal::operator=(cat);
		delete _brain;
		_brain = new Brain(*cat._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "=^..^= Meeeoww" << std::endl;
}

Brain* Cat::getBrain() {
	return _brain;
}