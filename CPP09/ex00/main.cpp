#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	std::map<std::string, float> container = {};

	if (ac != 2) {
		std::cout << "Please provide only 1 argument" << std::endl;
		return 1;
	}
	validateAdd(av[1], container);
	return 0;
}