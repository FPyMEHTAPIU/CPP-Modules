#include "BitcoinExchange.hpp"

static bool validateDate(const std::string& str) {
	const int shortMonths[] = {4, 6, 9, 11};
	size_t start = 0, end = 0;
	for (int i = 0; (start = str.find_first_not_of("-", end)) != std::string::npos; ++i) {
		if (i == 3) {
			throw(std::invalid_argument("bad input => " + str));
		}
		end = str.find('-', start);
		std::string sub = str.substr(start, end - start);
		int year = 0, month = 0, day = 0;
		std::cout << sub << std::endl;
		switch (i)
		{
		case 0:
			year = std::stoi(sub);
			if ((year <= 0 || year > 9999) || sub.length() != 4)
				throw(std::invalid_argument("bad input => " + str));
			break;
		case 1:
			month = std::stoi(sub);
			if ((month < 1 || month > 12) || sub.length() != 2)
				throw(std::invalid_argument("bad input => " + str));
			break;
		case 2:
			day = std::stoi(sub);
			if ((day < 1 || day > 31) || sub.length() != 2)
				throw(std::invalid_argument("bad input => " + str));
			if (month == 2) {
				if ((year % 4 == 0 && day > 29) || day > 28)
					throw(std::invalid_argument("bad input => " + str));
			} else if (std::find(std::begin(shortMonths), std::end(shortMonths), month) != std::end(shortMonths)) {
				if (month > 30)
					throw(std::invalid_argument("bad input => " + str));
			}
			break;
		default:
			break;
		}
	}
	return true;
}

static bool validateValue(const std::string& str) {
	if (str.length() > 4)
		throw(std::invalid_argument("bad input => " + str));
	int value = std::stoi(str);
	if (value < 0)
		throw(std::invalid_argument("not a positive number"));
	else if (value < 0)
		throw(std::invalid_argument("too large a number"));
	return true;
}

bool validateLine(const std::string& str) {
	return str.empty();
}

void printMap(std::map<std::string, float>& container) {
	for (auto item : container) { // replace auto
		std::cout << item.first << " => " << item.second << "\n";
	}
}

void validateAdd(std::string av, std::map<std::string, float>& container,
	const std::map<std::string, float>& database) {
	std::ifstream fd = std::ifstream(av);
	if (fd.fail()) {
		return ;
	}

	for (auto it : database) {
		std::cout << it.first << " " << it.second << "\n";
	}
	std::cout << std::endl;

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
		if (validateDate(data) && validateValue(value))
			container.emplace(data, std::stof(value));
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
	printMap(container);
}