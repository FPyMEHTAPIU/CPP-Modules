#include "utils.hpp"
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

bool write_field(Contact &contact, const int& i) {
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
	if (std::cin.eof())	return false;
	while (input.empty()) {
		std::cout << "This field cannot be empty!\n";
		getline(std::cin, input);
		if (std::cin.eof())	return false;
	}
	if (i == 3) {
		while (!isValidPhoneNumber(input)) {
			std::cout << "Phone number is invalid!\n";
			getline(std::cin, input);
			if (std::cin.eof())	return false;
		}
	}
	choose_and_set_field(contact, input, i);
	return true;
}

std::string format_field(const std::string& str) {
	if (str.length() > 10) {
		return (str.substr(0, WIDTH - 1) + ".");
	}
	return (str);
}

void print_contact_short(Contact contact, const int &index) {
	std::cout << std::setw(WIDTH) << format_field(std::to_string(index)) << "|"
		<< std::setw(WIDTH) << format_field(contact.getFirstName()) << "|"
		<< std::setw(WIDTH) << format_field(contact.getLastName()) << "|"
		<< std::setw(WIDTH) << format_field(contact.getNickname())<< std::endl;
}

void print_contact_full(Contact contact, const int &index) {
	std::cout << "Index: " << std::to_string(index) << "\n"
		<< "First name: " << contact.getFirstName() << "\n"
		<< "Last name: " << contact.getLastName() << "\n"
		<< "Nickname: " << contact.getNickname() << "\n"
		<< "Phone number: " << contact.getPhoneNumber() << "\n"
		<< "Darkest secret: " <<  contact.getDarkestSecret()
		<< std::endl;
}

bool isValidPhoneNumber(const std::string& number) {
    if (number.size() <= 1)
        return (false);
    size_t i = 0;
    if (number[0] == '+')
        ++i;
    for (; i < number.size(); ++i) {
        if (!isdigit(number[i]))
            return (false);
    }
    return (true);
}
