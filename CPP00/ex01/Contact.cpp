#include "Contact.hpp"

Contact::Contact() {
	firstName = "";
	lastName = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return (firstName);
}

std::string Contact::getLastName() {
	return (lastName);
}

std::string Contact::getPhoneNumber() {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() {
	return (darkestSecret);
}