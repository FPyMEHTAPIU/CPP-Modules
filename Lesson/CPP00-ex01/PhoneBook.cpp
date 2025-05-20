#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(): index(0) {
	for (int i = 0; i < 8; ++i) {
		contactList[i].setFirstName("");
	}
}

void PhoneBook::addNewContact() {
	fillContact();
	++index;
	if (index == 8)
		index = 0;
}

Contact &PhoneBook::findContactByIndex(int index) {
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index" << std::endl;
	} else if (contactList[index].getFirstName() == "") {
		std::cout << "The contact doesn't exist!" << std::endl;
	}
	return (contactList[index]);
}

void PhoneBook::fillContact() {
	Contact &contact = contactList[index];

	std::cout << "Segfault after this line" << std::endl;
	// const char newName[] = "First name";
	// write_field(newName, contact);
	write_field("First name", contact);
	write_field("Last name", contact);
	write_field("Nickname", contact);
	write_field("Phone number", contact);
	write_field("Darkest secret", contact);
}