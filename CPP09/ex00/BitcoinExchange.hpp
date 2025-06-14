#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <limits>
#include <string>

bool validateLine(const std::string& str);
void printMap();
void validateAdd(std::string av, std::map<std::string, float>& container);
void splitAdd(const std::string& line, std::map<std::string, float>& container);