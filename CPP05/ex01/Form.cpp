#include "Form.hpp"

Form::Form(): _isSigned(false), _GRADE_TO_SIGN(30), _GRADE_TO_EXEC(15) {}
Form::~Form() {}

Form::Form(Form const& other): 
	_GRADE_TO_SIGN(other._GRADE_TO_SIGN),
	_GRADE_TO_EXEC(other._GRADE_TO_EXEC) {
	*this = other;
}

Form& Form::operator=(Form const& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec):
	_NAME(name), _GRADE_TO_SIGN(gradeToSign), _GRADE_TO_EXEC(gradeToExec) {
	if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE) {
		throw GradeTooLowException("The grade is too low, provide something bellow 150!");
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "The grade is too high, provide something above 1!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string message):
	_message(message) {}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _GRADE_TO_SIGN) {
		throw GradeTooLowException("The grade is lower than required to sign. Sorry.");
	}
	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _NAME << std::endl;
}

const std::string& Form::getName() const {
	return _NAME;
}

const bool& Form::getIsSigned() const {
	return _isSigned;
}

const int& Form::getGradeToSign() const {
	return _GRADE_TO_SIGN;
}

const int& Form::getGradeToExec() const {
	return _GRADE_TO_EXEC;
}

std::ostream& operator<<(std::ostream &out, Form const& form) {
	out << "Form name: " << form.getName() << "\n"
		<< "Signed status: " << form.getIsSigned() << "\n"
		<< "Grade to sign: " << form.getGradeToSign() << "\n"
		<< "Grade to exec: " << form.getGradeToExec();
	return out; 
}