#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message):
	_message(message) {}

Bureaucrat::Bureaucrat(): _NAME("Buddy"), _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(Bureaucrat const& other): _NAME(other._NAME) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, const int grade): _NAME(name) {
	if (grade < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (grade > MIN_GRADE) {
		throw GradeTooLowException("the grade is too low, provide something bellow 150!");
	}
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _NAME;
}

const int& Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const& bureaucrat) {
	out << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::increaseGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (_grade == 150)
		throw GradeTooLowException("the grade is the lowest possible ever. The bottom has reached :(");
	_grade++;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << _NAME <<  " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << _NAME << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}