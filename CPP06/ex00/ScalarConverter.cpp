#include "ScalarConverter.hpp"

static void printImpossible() {
	std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible\n";
}

static void checkPrintChar(const double& d) {
	std::string status;

	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		status = "impossible";
	else if (!isprint(d))
		status = "Non displayable";
	else
		status += static_cast<char>(d);
	std::cout << "char: " << status << "\n";
}

static void validateInt(const double& d) {
	int i;

	if (std::isnan(d) || std::isinf(d)
		|| d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible\n";
	}
	else {
		try {
			i = static_cast<int>(d);
			std::cout << "int: " << i << "\n";
		} catch(...) {
			std::cout << "int: impossible\n";
		}
	}
}

static void validateFloat(const double& d, t_numtype type) {
	float f;
	
	if (type == FLOATVAL) {
		if (d > std::numeric_limits<float>::max()
			|| d < std::numeric_limits<float>::min())
		{
			std::cout << "float: impossible\n";
		}
		else {
			try {
				f = static_cast<float>(d);
				std::cout << "float: " << std::setprecision(1) << f << "f\n";
			} catch (...) {
				std::cout << "float: impossible\n";
			}
		}
	}
	else {
		if (d > std::numeric_limits<double>::max()
			|| d < std::numeric_limits<double>::min())
		{
			std::cout << "double: impossible\n";
		}
		else {
			try {
				std::cout << "double: " << std::setprecision(1) << d << "\n";
			} catch (...) {
				std::cout << "double: impossible\n";
			}
		}
	}
	
}

static void checkPrintNumber(const double& d, t_numtype type) {
	switch (type)
	{
	case INTVAL:
		validateInt(d);
		break;
	case FLOATVAL:
		validateFloat(d, type);
		break;
	case DOUBLEVAL:
		validateFloat(d, type);
		break;
	default:
		break;
	}
}

void ScalarConverter::convert(const std::string& value) {
	double d;

	if (value == "-inf" || value == "-inff") {
		d = -std::numeric_limits<double>::infinity();
	} else if (value == "+inf" || value == "+inff"
		|| value == "inf" || value == "inff") {
		d = std::numeric_limits<double>::infinity();
	} else if (value == "nan" || value == "nanf") {
		d = std::numeric_limits<double>::quiet_NaN();
	} else if (value.size() == 1) {
		d = static_cast<double>(value[0]);
	} else {
		try {
			d = std::stod(value);
		} catch (std::exception&) {
			printImpossible();
			return;
		}
	}
	checkPrintChar(d);
	checkPrintNumber(d, INTVAL);
	std::cout << std::fixed;
	checkPrintNumber(d, FLOATVAL);
	checkPrintNumber(d, DOUBLEVAL);
}