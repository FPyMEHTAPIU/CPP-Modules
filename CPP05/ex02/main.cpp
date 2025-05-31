#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat joe("Joe", 140);
		Bureaucrat tim("Tim", 70);
		Bureaucrat lowRank("LowRank", 150);

		std::cout << "\n=== ShrubberyCreationForm ===\n";
		ShrubberyCreationForm shrubForm("home");
		std::cout << shrubForm << std::endl;
		shrubForm.beSigned(joe);
		joe.executeForm(shrubForm); // not enough exec grade
		bob.executeForm(shrubForm); // success, creates file

		std::cout << "\n=== RobotomyRequestForm ===\n";
		RobotomyRequestForm robotForm("Bender");
		std::cout << robotForm << std::endl;
		robotForm.beSigned(tim);
		for (int i = 0; i < 4; ++i) {
			bob.executeForm(robotForm); // try multiple times
		}

		std::cout << "\n=== PresidentialPardonForm ===\n";
		PresidentialPardonForm pardonForm("Arthur Dent");
		std::cout << pardonForm << std::endl;
		pardonForm.beSigned(bob);
		bob.executeForm(pardonForm); // success

		std::cout << "\n=== Not Signed Form ===\n";
		PresidentialPardonForm notSignedForm("Zaphod");
		lowRank.executeForm(notSignedForm); // throws not signed

		std::cout << "\n=== Too Low To Sign ===\n";
		RobotomyRequestForm lowForm("Marvin");
		lowRank.signForm(lowForm); // throws too low to sign

	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}