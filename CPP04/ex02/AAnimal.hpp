#pragma once
#include <iostream>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(AAnimal const& animal);
		virtual ~AAnimal();
		AAnimal& operator=(AAnimal const& animal);
		virtual void makeSound() const = 0;
		std::string getType() const;
};