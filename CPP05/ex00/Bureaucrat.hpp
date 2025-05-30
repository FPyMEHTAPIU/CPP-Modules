#pragma once
#include <iostream>
#include <exception>

const int MIN_GRADE = 150;
const int MAX_GRADE = 1;

class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};

class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
};

class Bureaucrat {
	private:
		const std::string _name = "Buddy";
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat();
		Bureaucrat& operator=(Bureaucrat const& other);
		Bureaucrat(const int grade);

		const std::string& getName() const;
		const int& getGrade() const;

		void increaseGrade();
		void decreaseGrade();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const& bureaucrat);