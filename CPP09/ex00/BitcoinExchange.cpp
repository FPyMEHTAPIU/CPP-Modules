#include "BitcoinExchange.hpp"

bool validateLine(const std::string& str) {
	return str.empty();
}

void printMap() {

}

void validateAdd(std::string av, std::map<std::string, float>& container) {
	std::ifstream fd = std::ifstream(av);
	if (fd.fail()) {
		return ;
	}

	std::string str;
	while (getline(fd, str)) {
		splitAdd(str, container);
	}
	fd.close();
}

void splitAdd(const std::string& line, std::map<std::string, float>& container) {
	std::string data, value;
	size_t start;
	size_t end = 0;
	while ((start = line.find_first_not_of(" ", end)) != std::string::npos)
	{
		end = line.find(" ", start);
		if (line[start] == '|')
			continue ;
		if (start == 0)
			data = line.substr(start, end - start);
		else
			value = line.substr(start, end - start);
	}
	try {
		container.emplace(data, std::stof(value));
	} catch (...) {
		std::cout << "Incorrect value" << std::endl;
		return ;
	}
	std::cout << container.begin()->first << " " << container.begin()->second << std::endl;
}