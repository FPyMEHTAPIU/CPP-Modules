#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void search(PhoneBook &phonebook) {
	int curIndex = phonebook.getIndex();
	int	indexToSearch;

	std::cout << std::setw(WIDTH) << format_field("Index") << "|"
		<< std::setw(WIDTH) << format_field("First name") << "|"
		<< std::setw(WIDTH) << format_field("Last name") << "|"
		<< std::setw(WIDTH) << format_field("Nickname")<< "|"
		<< std::endl;

	for (int i = 0; i < curIndex; ++i) {
		print_contact_short(phonebook.findContactByIndex(i), i);
	}

	std::cout << "Enter an index to get full information about a user" << std::endl;
	std::cin >> indexToSearch;
	Contact contact = phonebook.findContactByIndex(indexToSearch);
	while (contact.getFirstName() == "") {
		std::cin >> indexToSearch;
		contact = phonebook.findContactByIndex(indexToSearch);
	}
	std::cin.ignore();
	print_contact_full(contact, indexToSearch);
}

int main() {
	PhoneBook phonebook;
	std::string input;

	while (1) {
		std::cout << "Enter one of the following commands: ADD | SEARCH | EXIT" << std::endl;
		
		if (!getline(std::cin, input)) {
			std::cout << "EOF reached!" << std::endl;
			break;
		} else if (input.empty()) {
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