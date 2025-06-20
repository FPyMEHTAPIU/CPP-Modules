#include "BitcoinExchange.hpp"

static std::map<std::string, float> parseDatabase() {
	std::map<std::string, float> database;

	std::ifstream fd = std::ifstream("data.csv");
	if (fd.fail()) {
		std::cout << "Failed to open the DB." << std::endl;
		exit(1);
	}
	std::string line, date, valueStr;
	getline(fd, line);
	while (getline(fd, line)) {
		size_t delimeter = line.find(',');
		if (delimeter == std::string::npos) {
			std::cout << "DB is in wrong format" << std::endl;
			fd.close();
			exit(1);
		}
		date = line.substr(0, delimeter);
		if (date.length() != 10) {
			std::cout << "DB is in wrong format" << std::endl;
			fd.close();
			exit(1);
		}
		delimeter++;
		valueStr = line.substr(delimeter, line.size() - delimeter);
		try {
			float value = std::stof(valueStr);
			database.emplace(date, value);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	fd.close();
	return database;
}

int main(int ac, char** av) {
	std::map<std::string, float> container;
	std::map<std::string, float> database;

	if (ac != 2) {
		std::cout << "Please provide only 1 argument" << std::endl;
		return 1;
	}
	database = parseDatabase();
	validateAdd(av[1], container, database);
	//printMap(container, database);
	//std::cout << container.size() << std::endl;
	return 0;
}