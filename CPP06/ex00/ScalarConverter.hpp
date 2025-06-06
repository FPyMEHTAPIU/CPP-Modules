#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

typedef enum e_numtype {
	INTVAL,
	FLOATVAL,
	DOUBLEVAL,
}	t_numtype;

class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter const& other) = delete;
		ScalarConverter& operator=(ScalarConverter const& other) = delete;
		~ScalarConverter() = delete;
	
	public:
		static void convert(const std::string& value);
};