#include "RPN.hpp"

static std::vector<std::string> split(const std::string& str, char del) {
    std::vector<std::string> vec;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(del, end)) != std::string::npos)
	{
		end = str.find(del, start);
		vec.push_back(str.substr(start, end - start));
	}
	return vec;
}

// static void countArgs(const std::vector<std::string>& vec) {

// }

static void validateArg(const std::string& arg) {
    if (arg == "-" || arg == "+" || arg == "*" || arg == "/")
        return ;
    int num = std::stoi(arg);
    if (num > 9 || num < -9)
        throw(std::out_of_range("Number is out of range"));
}

void calculate(int& result, int arg2, char action) {
    switch (action)
    {
    case '-':
        result -= arg2;
        break;
    case '+':
        result += arg2;
        break;
    case '*':
        result *= arg2;
        break;
    case '/':
        if (arg2 == 0)
            throw(std::invalid_argument("Division by 0"));
        result /= arg2;
        break ;
    default:
        break;
    }
}

void RPN(const std::string& arg) {
    std::vector<std::string> vec = split(arg, ' ');
    if (vec.size() < 3)
        throw(std::invalid_argument("Not enough arguments"));
    
    int result = 0;
    int arg2;

    validateArg(*vec.begin());
    result = std::stoi(*vec.begin());
    for (std::vector<std::string>::iterator arg = vec.begin() + 1; arg != vec.end(); arg++) {
        validateArg(*vec.begin());
        if (*arg == "-" || *arg == "+" || *arg == "*" || *arg == "/")
            calculate(result, arg2, (*arg)[0]);
        else
            arg2 = std::stoi(*arg);
    }

    std::cout << result << std::endl;
}