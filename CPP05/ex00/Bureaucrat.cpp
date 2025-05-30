#include "Bureaucrat.hpp"

const char* GradeTooHighException::what() const throw() {
	return "The grade is too high, provide something above 1!";
}

const char* GradeTooLowException::what() const throw() {
	return "The grade is too high, provide something bellow 150!";
}

Bureaucrat::Bureaucrat(): _grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(Bureaucrat const& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const int grade) {
	if (grade < MAX_GRADE) {
		throw GradeTooHighException();
	} else if (grade > MIN_GRADE) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _name;
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
		throw GradeTooLowException();
	_grade++;
}