#include "PhoneBook.hpp"
#include <iostream>

void print_contact(Contact contact) {
	(void) contact;
}

void search(const PhoneBook &phonebook) {
	(void) phonebook;
	std::cout << "It will print later =)\n";
}

int main() {
	PhoneBook phonebook;
	std::string input;

	while (1) {
		std::cout << "Enter one of the following commands: ADD | SEARCH | EXIT" << std::endl;
		getline(std::cin, input);
		if (input.empty()) {
			continue;
		} else if (input == "ADD") {
			phonebook.addNewContact();
		} else if (input == "SEARCH") {
			search(phonebook);
		} else if (input == "EXIT")
			break;
	}
	return (0);
}