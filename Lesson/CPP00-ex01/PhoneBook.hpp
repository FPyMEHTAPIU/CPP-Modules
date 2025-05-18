#pragma once
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contactList[8];
		int index;
	
	public:
		PhoneBook();
		void addNewContact();
		Contact &findContactByIndex(int index);

	private:
		void fillContact();
};