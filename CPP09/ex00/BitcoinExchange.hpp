#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <limits>
#include <string>
#include <algorithm>

// void printMap(const std::map<std::string, float>& container,
// 	const std::map<std::string, float>& database);
void validateAdd(std::string av, std::map<std::string, float>& container,
	const std::map<std::string, float>& database);
void splitAdd(const std::string& line, std::map<std::string, float>& container,
	const std::map<std::string, float>& database);
bool validateDate(const std::string& str);
bool validateValue(const std::string& str);