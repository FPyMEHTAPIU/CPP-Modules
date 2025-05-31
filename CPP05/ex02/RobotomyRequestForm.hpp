#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(RobotomyRequestForm const& other) = delete;
		RobotomyRequestForm& operator=(RobotomyRequestForm const& other) = delete;
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const& executor) const;
};