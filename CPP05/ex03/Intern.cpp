#include "Intern.hpp"

namespace 
{
	const std::string requests[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*const formArr[3])(const std::string&) = {
		[](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
		[](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
		[](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
	};
}

Intern::Intern() {}
Intern::~Intern() {}

const char* Intern::FormNotFound::what() const throw() {
	return "The form doesn't exist.";
}

AForm* Intern::makeForm(std::string formName, std::string targetName) {
	for (int i = 0; i < 3; ++i) {
		if (formName == requests[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formArr[i](targetName);
		}
	}
	throw FormNotFound();
	return nullptr;
}