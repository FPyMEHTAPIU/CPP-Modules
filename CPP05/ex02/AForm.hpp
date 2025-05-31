#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _NAME;
		bool _isSigned;
		const int _GRADE_TO_SIGN;
		const int _GRADE_TO_EXEC;

	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const& other);
		AForm& operator=(AForm const& other);

		AForm(std::string name, int gradeToSign, int gradeToExec);

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

		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream &out, AForm const& form);