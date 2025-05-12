#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void search(PhoneBook &phonebook) {
	int contactsNumber = phonebook.countContacts();
	std::string input;
	int	indexToSearch;
	Contact contact;

	if (phonebook.isContactListEmpty()) {
		std::cout << "The phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << std::setw(WIDTH) << format_field("Index") << "|"
		<< std::setw(WIDTH) << format_field("First name") << "|"
		<< std::setw(WIDTH) << format_field("Last name") << "|"
		<< std::setw(WIDTH) << format_field("Nickname")<< "|"
		<< std::endl;

	for (int i = 0; i < contactsNumber; ++i) {
		print_contact_short(phonebook.findContactByIndex(i), i);
	}

	do {
		std::cout << "Enter an index to get full information about a user" << std::endl;
		try {
			std::cin >> input;
			indexToSearch = std::stoi(input);
			contact = phonebook.findContactByIndex(indexToSearch);
		} catch (const std::invalid_argument &) {
			std::cout << "The value must be decimal!" << std::endl;
		}
	} while (contact.getFirstName() == "");
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