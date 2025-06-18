#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <limits>
#include <string>
#include <algorithm>

bool validateLine(const std::string& str);
void printMap(std::map<std::string, float>& container);
void validateAdd(std::string av, std::map<std::string, float>& container,
	const std::map<std::string, float>& database);
void splitAdd(const std::string& line, std::map<std::string, float>& container);