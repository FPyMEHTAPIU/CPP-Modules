#include "AForm.hpp"

AForm::AForm(): _isSigned(false), _GRADE_TO_SIGN(30), _GRADE_TO_EXEC(15) {}
AForm::~AForm() {}

AForm::AForm(AForm const& other): 
	_GRADE_TO_SIGN(other._GRADE_TO_SIGN),
	_GRADE_TO_EXEC(other._GRADE_TO_EXEC) {
	*this = other;
}

AForm& AForm::operator=(AForm const& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec):
	_NAME(name), _GRADE_TO_SIGN(gradeToSign), _GRADE_TO_EXEC(gradeToExec) {
	if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE) {
		throw GradeTooLowException("The grade is too low, provide something bellow 150!");
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "The grade is too high, provide something above 1!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string message):
	_message(message) {}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _GRADE_TO_SIGN) {
		throw GradeTooLowException("The grade is lower than required to sign. Sorry.");
	}
	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _NAME << std::endl;
}

const std::string& AForm::getName() const {
	return _NAME;
}

const bool& AForm::getIsSigned() const {
	return _isSigned;
}

const int& AForm::getGradeToSign() const {
	return _GRADE_TO_SIGN;
}

const int& AForm::getGradeToExec() const {
	return _GRADE_TO_EXEC;
}

std::ostream& operator<<(std::ostream &out, AForm const& form) {
	out << "AForm name: " << form.getName() << "\n"
		<< "Signed status: " << (form.getIsSigned() ? "yes" : "no") << "\n"
		<< "Grade to sign: " << form.getGradeToSign() << "\n"
		<< "Grade to exec: " << form.getGradeToExec();
	return out; 
}