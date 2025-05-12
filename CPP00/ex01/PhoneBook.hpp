#pragma once
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contactList[8];
		int _index;
	
	public:
		PhoneBook();
		void addNewContact();
		Contact findContactByIndex(int index);
		int getIndex() const;
		bool isContactListEmpty();
		int	countContacts();

	private:
		void fillContact();
};