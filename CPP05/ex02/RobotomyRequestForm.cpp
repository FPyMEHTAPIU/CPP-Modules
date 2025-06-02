#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::srand(std::time(nullptr));
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("the grade is not enough to execute in RobotomyRequestForm");

	std::cout << "Making drilling noises..." << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << _target << " robotomizy has failed." << std::endl;
	}
}