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

Contact PhoneBook::findContactByIndex(int index) {
	Contact tempContact;
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index" << std::endl;
		return (tempContact);
	} else if (contactList[index].getFirstName() == "") {
		std::cout << "The contact doesn't exist!" << std::endl;
		return (tempContact);
	}
	return (contactList[index]);
}

int PhoneBook::getIndex() const {
	return (index);
}

void PhoneBook::fillContact() {
	Contact& contact = contactList[index];

	for (int i = 0; i < 5; ++i) {
		write_field(contact, i);
	}
}