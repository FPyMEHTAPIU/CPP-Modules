#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(Cat const& cat);
		~Cat();
		Cat& operator=(Cat const& cat);
		void makeSound() const;

		Brain* getBrain();
};