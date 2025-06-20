#include "BitcoinExchange.hpp"

bool validateDate(const std::string& str) {
	const int shortMonths[] = {4, 6, 9, 11};
	size_t start = 0, end = 0;
	int year = 0, month = 0, day = 0;
	for (int i = 0; (start = str.find_first_not_of("-", end)) != std::string::npos; ++i) {
		if (i == 3) {
			throw(std::invalid_argument("bad input => " + str));
		}
		end = str.find('-', start);
		std::string sub = str.substr(start, end - start);

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
			else if (month == 2) {
				if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
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

bool validateValue(const std::string& str) {
	int value = 0;
	try {
		value = std::stoi(str);
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
	const std::map<std::string, float>& database)
{
	std::ifstream fd = std::ifstream(av);
	if (fd.fail()) {
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
			for (const std::pair<std::string, float> item: container) {
				if (date == item.first) {
					container.erase(date);
					break;
				}
			}

			container.emplace(date, std::stof(value));
			
			std::pair<std::string, float> neededDate;

			for (const std::pair<const std::string, float>& dbItem: database) {
				if (date <= dbItem.first)
					break;
				neededDate = dbItem;
			}

			std::cout << date << " => " << value << " = "
				<< container.find(date)->second * neededDate.second
				<< std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
}
