#pragma once
#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& arg1, int arg2) {
	typename T::iterator it = std::find(arg1.begin(), arg1.end(), arg2);
	if (it == arg1.end())
		throw std::invalid_argument("Object not found");
	return it;
}