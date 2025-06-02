#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat john("John", 50);
		Form form("Important Document", 47, 30);
		
		std::cout << john << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;
		john.increaseGrade();
		john.increaseGrade();
		john.increaseGrade();
		john.increaseGrade();
		std::cout << john << std::endl;
		john.signForm(form);
		std::cout << form << std::endl;
		Bureaucrat mike("Mike", 550);
		std::cout << form << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}