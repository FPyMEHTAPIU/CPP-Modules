#pragma once
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contactList[8];
		int index;
	
	public:
		PhoneBook();
		void addNewContact();
		Contact findContactByIndex(int index);
		int getIndex() const;
		bool isContactListEmpty();

	private:
		void fillContact();
};