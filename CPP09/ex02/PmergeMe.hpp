#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

std::vector<std::string> split(const std::string& str, char del);
void pmegreMe(char **av, int ac);
std::vector<size_t> generateJacobsthal(size_t size);
void vectorSort(std::vector<int>& vec);
void dequeSort(std::deque<int>& deq);

template <typename T>
T validateAdd(char **av, int ac) {
	T container;

	if (ac == 2) {
		std::vector<std::string> strs = split(av[0], ' ');
		for (const std::string& str: strs) {
			int num = std::stoi(str);
			if (num < 0)
				throw(std::invalid_argument("A number must be positive"));
			container.push_back(num);
		}
	} else {
		for (int i = 0; av[i]; ++i) {
			int num = std::stoi(av[i]);
			if (num < 0)
				throw(std::invalid_argument("A number must be positive"));
			container.push_back(num);
		}
	}

	return container;
}

template <typename T>
void printContainer(const std::string& prefix, const T& container) {
	std::cout << prefix;
	if (container.size() > 5) {
		for (size_t i = 0; i < 4; ++i) {
			std::cout << container[i] << " ";
		}
		std::cout << "[...]";
	} else {
		for (size_t i = 0; i < container.size(); ++i) {
			std::cout << container[i];
			if (i + 1 < container.size())
				std::cout << " ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
void sortFordJohnson(T& container) {
	if (container.size() <= 1) return;

	T min, max;

	size_t i = 0;
	for (; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			max.push_back(container[i + 1]);
			min.push_back(container[i]);
		} else {
			max.push_back(container[i]);
			min.push_back(container[i + 1]);
		}
	}
	if (i < container.size()) 
		min.push_back(container[i]);

	sortFordJohnson(max);

	T res = max;
	std::vector<size_t> jacobNumbers = generateJacobsthal(min.size());
	std::vector<bool> isInserted(min.size(), false);
	std::vector<bool> alreadyUsed(min.size(), false);

	for (size_t j = 0; j < jacobNumbers.size(); ++j) {
		size_t index = jacobNumbers[j];
		if (index < min.size() && !alreadyUsed[index]) {
			typename T::iterator pos = std::lower_bound(res.begin(), res.end(), min[index]);
			res.insert(pos, min[index]);
			isInserted[index] = true;
			alreadyUsed[index] = true;
		}
	}

	for (size_t j = 0; j < min.size(); j++) {
		if (!isInserted[j]) {
			typename T::iterator pos = std::lower_bound(res.begin(), res.end(), min[j]);
			res.insert(pos, min[j]);
			isInserted[j] = true;
		}
	}
	container = res;
}