#include "BitcoinExchange.hpp"

bool validateDate(const std::string& str) {
	const int shortMonths[] = {4, 6, 9, 11};
	size_t start = 0, end = 0;
	int year = 0, month = 0, day = 0;
	if (str.empty())
		return false;
	for (int i = 0; (start = str.find_first_not_of("-", end)) != std::string::npos; ++i) {
		if (i == 3) {
			throw(std::invalid_argument("bad input => " + str));
		}
		end = str.find('-', start);
		std::string sub = str.substr(start, end - start);

		switch (i)
		{
		case 0:
			try {
				year = std::stoi(sub);
			} catch (...) {
				throw(std::invalid_argument("bad input => " + str));
			}
			if ((year <= 0 || year > 9999) || sub.length() != 4)
				throw(std::invalid_argument("bad input => " + str));
			break;
		case 1:
			try {
				month = std::stoi(sub);
			} catch (...) {
				throw(std::invalid_argument("bad input => " + str));
			}
			if ((month < 1 || month > 12) || sub.length() != 2)
				throw(std::invalid_argument("bad input => " + str));
			break;
		case 2:
			try {
				day = std::stoi(sub);
			} catch (...) {
				throw(std::invalid_argument("bad input => " + str));
			}
			
			if ((day < 1 || day > 31) || sub.length() != 2)
				throw(std::invalid_argument("bad input => " + str));
			else if (month == 2) {
				if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
					throw(std::invalid_argument("bad input => " + str));
			} else if (std::find(std::begin(shortMonths), std::end(shortMonths), month) != std::end(shortMonths)) {
				if (day > 30)
					throw(std::invalid_argument("bad input => " + str));
			}
			break;
		default:
			break;
		}
	}
	return true;
}

bool validateValue(const std::string& str) {
	float value = 0;
	try {
		value = std::stof(str);
	} catch (std::out_of_range&) {
		throw(std::out_of_range("too large a number"));
	} catch (std::invalid_argument&) {
		throw(std::invalid_argument("not a number"));
	}
	if (value < 0)
		throw(std::invalid_argument("not a positive number"));
	return true;
}

void validateAdd(std::string av, std::map<std::string, float>& container,
	std::map<std::string, float>& database)
{
	std::ifstream fd = std::ifstream(av);
	if (fd.fail()) {
		database.clear();
		std::cout << "File opening failed" << std::endl;
		exit(1);
	}

	std::string str;
	getline(fd, str);
	while (getline(fd, str)) {
		splitAdd(str, container, database);
	}
	fd.close();
}

void splitAdd(const std::string& line, std::map<std::string, float>& container,
	const std::map<std::string, float>& database)
{
	std::string date, value;
	size_t start;
	size_t end = 0;
	while ((start = line.find_first_not_of(" ", end)) != std::string::npos)
	{
		end = line.find(" ", start);
		if (line[start] == '|')
			continue ;
		if (start == 0)
			date = line.substr(start, end - start);
		else
			value = line.substr(start, end - start);
	}
	try {
		if (validateDate(date) && validateValue(value))
		{
			container.erase(date);
			container.emplace(date, std::stof(value));
			
			std::map<std::string, float>::const_iterator it = database.lower_bound(date);
			if (it != database.end() && it->first == date) {
				std::cout << date << " => " << value << " = "
					<< std::stof(value) * it->second << std::endl;
			} else {
				if (it == database.begin()) {
					std::cout << date << " => " << value << " = 0" << std::endl;
				} else {
					--it;
					std::cout << date << " => " << value << " = "
						<< std::stof(value) * it->second << std::endl;
				}
			}
		} else {
			throw(std::invalid_argument("bad input => " + line));
		}
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
}
