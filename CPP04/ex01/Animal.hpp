#pragma once
#include <iostream>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(Animal const& animal);
		virtual ~Animal();
		Animal& operator=(Animal const& animal);
		virtual void makeSound() const;
		std::string getType() const;
};