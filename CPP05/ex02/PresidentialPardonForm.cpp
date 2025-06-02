#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("the grade is not enough to execute in PresidentialPardonForm");

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}