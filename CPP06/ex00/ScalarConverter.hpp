#pragma once
#include <iostream>
#include <string>
#include <iomanip>

typedef enum e_type {
	CHARVAL,
	INTVAL,
	FLOATVAL,
	DOUBLEVAL,
	INF_POS,
	INF_NEG,
	NAN
}	t_type;

class ScalarConverter {
	private:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter const& other) = delete;
		ScalarConverter& operator=(ScalarConverter const& other) = delete;
		~ScalarConverter() = delete;
	
	public:
		static void convert(const std::string& value);
};