#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(): _index(0) {
	for (int i = 0; i < 8; ++i) {
		_contactList[i].setFirstName("");
	}
}

void PhoneBook::addNewContact() {
	fillContact();
	++_index;
	if (_index == 8)
		_index = 0;
}

Contact PhoneBook::findContactByIndex(int index) {
	Contact tempContact;
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index" << std::endl;
		return (tempContact);
	} else if (_contactList[index].getFirstName() == "") {
		std::cout << "The contact doesn't exist!" << std::endl;
		return (tempContact);
	}
	return (_contactList[index]);
}

int	PhoneBook::countContacts() {
	int	count = 0;

	for (Contact &contact: _contactList) {
		if (contact.getFirstName() != "")
			count++;
		else
			break;
	}
	return (count);
}

void PhoneBook::fillContact() {
	Contact& contact = _contactList[_index];

	for (int i = 0; i < 5; ++i) {
		write_field(contact, i);
	}
}

bool PhoneBook::isContactListEmpty() {
	return (_contactList[0].getFirstName() == "");
}