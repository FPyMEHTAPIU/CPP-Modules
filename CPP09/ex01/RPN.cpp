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

static bool isOperator(const std::string& arg) {
    if (arg == "-" || arg == "+" || arg == "*" || arg == "/")
        return true;
    return false;
}

static void validateArg(const std::string& arg) {
    if (arg == "-" || arg == "+" || arg == "*" || arg == "/")
        return ;
    int num = std::stoi(arg);
    if (num > 9 || num < -9)
        throw(std::out_of_range("Number is out of range"));
}

static void countArgs(const std::vector<std::string>& vec) {
    int nums = 0, operators = 0;
    for (const std::string& arg: vec) {
        validateArg(arg);
        if (isOperator(arg))
            operators++;
        else {
            std::stoi(arg);
            nums++;
        }
    }
    if (operators != nums - 1)
        throw(std::invalid_argument("Wrong number of operators"));
}

static void calculate(std::vector<int>& result, char action) {
    if (result.size() > 3)
        throw(std::invalid_argument("Not possible to perform a calculation"));
    int arg1;
    int arg2;
    if (result.size() == 3) {
        arg1 = result.at(1);
        arg2 = result.at(2);
    } else {
        arg1 = result.at(0);
        arg2 = result.at(1);
    }
    for (int i = 0; i < 2; ++i)
        result.pop_back();
    switch (action)
    {
    case '-':
        result.push_back(arg1 - arg2);
        break;
    case '+':
        result.push_back(arg1 + arg2);
        break;
    case '*':
        result.push_back(arg1 * arg2);
        break;
    case '/':
        if (arg2 == 0)
            throw(std::invalid_argument("Division by 0"));
        result.push_back(arg1 / arg2);
        break ;
    default:
        break;
    }
}

void RPN(const std::string& arg) {
    std::vector<std::string> vec = split(arg, ' ');
    if (vec.size() < 3)
        throw(std::invalid_argument("Not enough arguments"));

    countArgs(vec);
    std::vector<int> result;
    for (std::vector<std::string>::iterator arg = vec.begin(); arg != vec.end(); arg++) {
        if (*arg == "-" || *arg == "+" || *arg == "*" || *arg == "/")
            calculate(result, (*arg)[0]);
        else if (result.size() > 3) {
            throw(std::invalid_argument("To many numbers in a row"));
        }
        else
            result.push_back(std::stoi((*arg)));
    }

    if (result.size() != 1)
        throw(std::invalid_argument("Incorrect number of args"));
    std::cout << result.at(0) << std::endl;
}