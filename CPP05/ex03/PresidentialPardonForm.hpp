#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(PresidentialPardonForm const& other) = delete;
		PresidentialPardonForm& operator=(PresidentialPardonForm const& other) = delete;
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		void execute(Bureaucrat const& executor) const;
};
