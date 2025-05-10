#pragma once
#include <iostream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};