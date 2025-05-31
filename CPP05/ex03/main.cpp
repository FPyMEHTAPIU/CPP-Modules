#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    Intern intern;

    std::cout << "=== Valid form names ===" << std::endl;

    try {
        AForm* shrubbery = intern.makeForm("shrubbery creation", "Home");
        std::cout << *shrubbery << std::endl;
        delete shrubbery;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        std::cout << *robotomy << std::endl;
        delete robotomy;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *pardon << std::endl;
        delete pardon;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid form name ===" << std::endl;

    try {
        AForm* unknown = intern.makeForm("unknown form", "Nobody");
		if (!unknown)
        std::cout << *unknown << std::endl;
        delete unknown;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
