#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

void print_contact(Contact contact) {
	(void) contact;
}

void search(const PhoneBook &phonebook) {
	(void) phonebook;
	std::cout << "It will print later =)\n";
}


void handle_add_contact(PhoneBook &phonebook) {
	write_field("First name", phonebook);
	write_field("Last name", phonebook);
	write_field("Nickname", phonebook);
	write_field("Phone number", phonebook);
	write_field("Darkest secret", phonebook);
}

int main() {
	PhoneBook phonebook;
	std::string input;

	while (1) {
		std::cout << "Enter one of the following commands: ADD | SEARCH | EXIT\n";
		getline(std::cin, input);
		if (input == "") {
			continue;
		} else if (input == "ADD") {
			handle_add_contact(phonebook);
		} else if (input == "SEARCH") {
			search(phonebook);
		} else if (input == "EXIT")
			break;
	}
	std::cout << std::endl;
	return (0);
}