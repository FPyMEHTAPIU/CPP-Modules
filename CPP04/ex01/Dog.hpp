#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(Dog const& dog);
		~Dog();
		Dog& operator=(Dog const& dog);
		void makeSound() const;

		Brain* getBrain();
};