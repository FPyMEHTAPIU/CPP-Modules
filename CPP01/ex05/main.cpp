#include <iostream>
#include "Harl.hpp"

int main() {
	Harl harlic;

	harlic.complain("DEBUG");
	harlic.complain("INFO");
	harlic.complain("WARNING");
	harlic.complain("ERROR");
	return 0;
}