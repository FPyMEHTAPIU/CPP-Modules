#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {
	for (int i = 0; i < 8; ++i) {
		contactList[i].setFirstName("");
	}
}

void PhoneBook::addNewContact(Contact newContact) {
	contactList[index] = newContact;
	++index;
	if (index == 8)
		index = 0;
}

Contact PhoneBook::findContactByIndex(int index) {
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index" << std::endl;
	} else if (contactList[index].getFirstName() == "") {
		std::cout << "The contact doesn't exist!" << std::endl;
	}
	return (contactList[index]);
}