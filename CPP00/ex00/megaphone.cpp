#include <iostream>

static std::string str_to_upper(std::string &str) {
	std::string upperStr = "";

	for (char c : str) {
		upperStr += static_cast<char>(toupper(c));
	}
	return (upperStr);
}

int main(int ac, char **av) {
	std::string strToPrint = "";

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i) {
		std::string str = static_cast<std::string>(av[i]);
		strToPrint += str_to_upper(str);
	}
	std::cout << strToPrint << std::endl;
	return (0);
}