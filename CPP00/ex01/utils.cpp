#include "PhoneBook.hpp"

static void choose_and_set_field(const std::string fieldName, Contact &contact, std::string &input) {
	if (fieldName == "First name") {
		contact.setFirstName(input);
	} else if (fieldName == "Last name") {
		contact.setLastName(input);
	} else if (fieldName == "Nickname") {
		contact.setNickname(input);
	} else if (fieldName == "Phone number") {
		contact.setPhoneNumber(input);
	} else if (fieldName == "Darkest secret") {
		contact.setDarkestSecret(input);
	}
}

void write_field(const std::string fieldName, Contact &contact) {
	std::string input;

	std::cout << "Enter " << fieldName << std::endl;
	getline(std::cin, input);
	while (input.empty()) {
		std::cout << fieldName << " cannot be empty!\n";
		getline(std::cin, input);
	}
	choose_and_set_field(fieldName, contact, input);
}