#pragma once
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const& animal);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal const& animal);
		virtual void makeSound() const;
		std::string getType() const;
};