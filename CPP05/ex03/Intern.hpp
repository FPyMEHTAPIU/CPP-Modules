#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const& other) = delete;
		Intern& operator=(Intern const& other) = delete;
		AForm* makeForm(std::string formName, std::string targetName);

		class FormNotFound : public std::exception {
			public:
				const char* what() const throw();
		};
};

