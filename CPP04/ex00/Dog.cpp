#include "Dog.hpp"

Dog::Dog(): Animal() {
	type = "Dog";
}

Dog::Dog(Dog const& dog): Animal(dog) {
	*this = dog;
}

Dog::~Dog() {}

Dog& Dog::operator=(Dog const& dog) {
	if (this != &dog) {
		type = dog.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "ˁ(OᴥO)ˀ Bark!" << std::endl;
}