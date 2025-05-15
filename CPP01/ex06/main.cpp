#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[]) {
	Harl harlic;

	if (ac != 2) {
		std::cout << "It's a great day! Nothing to complain about!" << std::endl;
		return 0;
	}
	harlic.printLevels(av[1]);
	return 0;
}