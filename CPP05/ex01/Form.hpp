#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _NAME;
		bool _isSigned;
		const int _GRADE_TO_SIGN;
		const int _GRADE_TO_EXEC;

	public:
		Form();
		~Form();
		Form(Form const& other);
		Form& operator=(Form const& other);

		Form(std::string name, int gradeToSign, int gradeToExec);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _message;
			public:
				GradeTooLowException(std::string message);
				const char* what() const throw();
		};

		void beSigned(const Bureaucrat& bureaucrat);
		const std::string& getName() const;
		const bool& getIsSigned() const;
		const int& getGradeToSign() const;
		const int& getGradeToExec() const;
};

std::ostream& operator<<(std::ostream &out, Form const& form);