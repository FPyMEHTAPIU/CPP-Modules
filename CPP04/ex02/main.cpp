#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal **animals = new AAnimal*[50];

	for (int i = 0; i < 50; ++i) {
		if (i < 25)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 50; ++i) {
		delete animals[i];
	}

	delete[] animals;


	std::cout << "\n--- Deep copy test: Dog ---" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the cat");

	Dog copiedDog = originalDog;
	std::cout << "Original Dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

	originalDog.getBrain()->setIdea(0, "Eat a bone");

	std::cout << "After changing original:" << std::endl;
	std::cout << "Original Dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;


	std::cout << "\n--- Deep copy test: Cat ---" << std::endl;
	Cat originalCat;
	originalCat.getBrain()->setIdea(42, "Sleep all day");

	Cat copiedCat(originalCat);
	std::cout << "Original Cat's idea: " << originalCat.getBrain()->getIdea(42) << std::endl;
	std::cout << "Copied Cat's idea:   " << copiedCat.getBrain()->getIdea(42) << std::endl;

	originalCat.getBrain()->setIdea(42, "Knock things off the table");

	std::cout << "After changing original:" << std::endl;
	std::cout << "Original Cat's idea: " << originalCat.getBrain()->getIdea(42) << std::endl;
	std::cout << "Copied Cat's idea:   " << copiedCat.getBrain()->getIdea(42) << std::endl;

	return 0;
}
