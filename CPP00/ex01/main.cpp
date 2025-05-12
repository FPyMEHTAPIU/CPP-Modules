#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

const int WIDTH = 10;

static std::string format_field(const std::string& str) {
	if (str.length() > 10) {
		return (str.substr(0, WIDTH - 1) + ".");
	}
	return (str);
}

void print_contact_short(Contact contact, const int &index) {
	std::cout << std::setw(WIDTH) << format_field(std::to_string(index)) << "|"
		<< std::setw(WIDTH) << format_field(contact.getFirstName()) << "|"
		<< std::setw(WIDTH) << format_field(contact.getLastName()) << "|"
		<< std::setw(WIDTH) << format_field(contact.getNickname())<< "|"
		<< std::endl;
}

void search(PhoneBook &phonebook) {
	int curIndex = phonebook.getIndex();
	std::cout << std::setw(WIDTH) << format_field("Index") << "|"
		<< std::setw(WIDTH) << format_field("First name") << "|"
		<< std::setw(WIDTH) << format_field("Last name") << "|"
		<< std::setw(WIDTH) << format_field("Nickname")<< "|"
		<< std::endl;

	for (int i = 0; i < curIndex; ++i) {
		print_contact_short(phonebook.findContactByIndex(i), i);
	}
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