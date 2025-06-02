#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat borya("Borya", 4);
		Bureaucrat vitya("Vitya", 155);

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat borya("Borya", 1);
		
		borya.increaseGrade();

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat ilya("Ilya", 150);
		
		ilya.decreaseGrade();

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat kolya("Kolya", 5);
		
		kolya.increaseGrade();
		kolya.increaseGrade();
		kolya.increaseGrade();
		kolya.increaseGrade();
		std::cout << kolya << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat gradeless;
		
		std::cout << gradeless << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}