#include "Dog.hpp"

Dog::Dog(): Animal() {
	type = "Dog";
	std::cout << "Dog with a brain constructor" << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog const& dog): Animal(dog) {
	_brain = new Brain(*dog._brain);
	*this = dog;
}

Dog::~Dog() {
	std::cout << "Dog with a brain destructor" << std::endl;
	delete _brain;
}

Dog& Dog::operator=(Dog const& dog) {
	if (this != &dog) {
		Animal::operator=(dog);
		delete _brain;
		_brain = new Brain(*dog._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "ˁ(OᴥO)ˀ Bark!" << std::endl;
}

Brain* Dog::getBrain() {
	return _brain;
}