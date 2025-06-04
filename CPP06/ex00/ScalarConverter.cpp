#include "ScalarConverter.hpp"

bool validateChar(const std::string& value) {
	if (value[0] < 32 || value[0] > 126)
		return false;
	return true;
}

bool validateValue(const std::string& value, const t_type& type) {
	try {
		switch (type)
		{
		case INTVAL:
			std::stoi(value);
			return true;
			break;
		case FLOATVAL:
			std::stoi(value);
			std::stof(value);
			return true;
			break;
		case DOUBLEVAL:
			std::stoi(value);
			std::stof(value);
			std::stod(value);
			return true;
			break;
		
		default:
			return true;
		}
	} catch (std::out_of_range& e) {
		std::cerr << "Out of range " << e.what() << std::endl;
		return false;
	} catch (std::invalid_argument& e) {
		std::cerr << "Invalid argument " << e.what() << std::endl;
		return false;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	return false;
}

t_type checkType(const std::string& value) {
	if (value.size() == 1) 
		return CHARVAL;
	if (value.find('.') != std::string::npos) {
		if (value.find('f') != std::string::npos)
			return FLOATVAL;
		return DOUBLEVAL;
	}
	return INTVAL;
}

void ScalarConverter::convert(const std::string& value) {
	t_type type = checkType(value);

	if (!validateValue(value, type))
		return ;
	std::string charValue;
	if (validateChar(value))
		charValue += static_cast<char>(static_cast<int>(value[0]));
	else
		charValue = "Non displayable";

	int i = std::stoi(value);
	float f = std::stof(value);
	double d = std::stod(value);
	std::cout << "char: " << charValue << "\n"
		<< "int: " << i << "\n";
	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(1) << f << "f" << "\n";
	std::cout << "double: " << std::setprecision(1) << d << std::endl;
}