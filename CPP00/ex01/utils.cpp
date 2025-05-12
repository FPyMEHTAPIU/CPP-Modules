#include "PhoneBook.hpp"

void choose_and_set_field(Contact& contact, std::string& input, const int& i) {
	switch (i)
	{
	case 0:
		contact.setFirstName(input);
		break;
	case 1:
		contact.setLastName(input);
		break;
	case 2:
		contact.setNickname(input);
		break;
	case 3:
		contact.setPhoneNumber(input);
		break;
	case 4:
		contact.setDarkestSecret(input);
		break;
	default:
		break;
	}
}

void write_field(Contact &contact, const int& i) {
	std::string input;

	switch (i)
	{
	case 0:
		std::cout << "Enter first name" << std::endl;
		break;
	case 1:
		std::cout << "Enter last name" << std::endl;
		break;
	case 2:
		std::cout << "Enter nickname" << std::endl;
		break;
	case 3:
		std::cout << "Enter phone number" << std::endl;
		break;
	case 4:
		std::cout << "Enter darkest secret" << std::endl;
		break;
	default:
		break;
	}
	getline(std::cin, input);
	while (input.empty()) {
		std::cout << "This field cannot be empty!\n";
		getline(std::cin, input);
	}
	choose_and_set_field(contact, input, i);
}