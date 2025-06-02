#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

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
		throw GradeTooLowException();
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
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

void Bureaucrat::increaseGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}