#pragma once
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

const int WIDTH = 10;

void write_field(Contact &contact, const int& i);
std::string format_field(const std::string& str);
void print_contact_short(Contact contact, const int &index);
void print_contact_full(Contact contact, const int &index);