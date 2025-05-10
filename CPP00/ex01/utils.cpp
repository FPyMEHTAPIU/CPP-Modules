#include "PhoneBook.hpp"

static void choose_and_set_field(const std::string &fieldName, PhoneBook &phonebook, const std::string &input) {
	//TODO: add index and add to phonebook->contactList
	if (fieldName == "First name") {
		phonebook->setFirstName(input);
	} else if (fieldName == "Last name") {
		phonebook->setLastName(input);
	} else if (fieldName == "Nickname") {
		phonebook->setNickname(input);
	} else if (fieldName == "Phone number") {
		phonebook->setPhoneNumber(input);
	} else if (fieldName == "Darkest secret") {
		phonebook->setDarkestSecret(input);
	}
}

void write_field(const std::string &fieldName, PhoneBook &phonebook) {
	std::cout << "Enter " << fieldName << " \n";
	getline(std::cin, input);
	while (!input || input == "") {
		std::cin.ignore();
		std::cout << fieldName << " cannot be empty!\n";
		getline(std::cin, input);
	}
	choose_and_set_field(fieldName, phonebook, input);
}