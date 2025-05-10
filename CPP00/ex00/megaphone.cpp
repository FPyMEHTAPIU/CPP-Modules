#include <iostream>

void print_upper_str(std::string &str) {
	for (char c : str) {
		std::cout << static_cast<char>(toupper(c));
	}
}

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i) {
		std::string str = static_cast<std::string>(av[i]);
		print_upper_str(str);
	}
	std::cout << std::endl;
	return (0);
}