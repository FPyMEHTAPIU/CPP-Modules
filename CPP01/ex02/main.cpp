#include <iostream>

int main() {
	std::string	brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string& brainREF = brain;

	std::cout << "brain's memory addres: " << &brain << "\n";
	std::cout << "brainPTR's memory addres: " << brainPTR << "\n";
	std::cout << "brainREF's memory addres: " << &brainREF << "\n";
	std::cout << std::endl;

	std::cout << "brain's value: " << brain << "\n";
	std::cout << "brainPTR's value: " << *brainPTR << "\n";
	std::cout << "brainREF's value: " << brainREF << std::endl;
	return (0);
}