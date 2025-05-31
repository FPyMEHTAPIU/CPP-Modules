#pragma once
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(ShrubberyCreationForm const& other) = delete;
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other) = delete;
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const& executor) const;
};