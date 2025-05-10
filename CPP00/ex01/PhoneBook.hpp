#pragma once
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contactList[8];
		int index;
	
	public:
		PhoneBook();
		void addNewContact(Contact newContact);
		Contact findContactByIndex(int index);
};