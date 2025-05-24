#include "Dog.hpp"

Dog::Dog(): Animal() {
	type = "Dog";
	std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(Dog const& dog): Animal(dog) {
	*this = dog;
}

Dog::~Dog() {
	std::cout << type << " destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const& dog) {
	if (this != &dog) {
		type = dog.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "ˁ(OᴥO)ˀ Bark!" << std::endl;
}