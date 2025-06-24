#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

void pmegreMe(char **av);
std::vector<size_t> generateJacobsthal(size_t size);
void vectorSort(std::vector<int>& vec);
void dequeSort(std::deque<int>& deq);

template <template <typename, typename> class T>
T<int, std::allocator<int>> validateAdd(char **av) {
   T<int, std::allocator<int>> container;

    for (int i = 0; av[i]; ++i) {
        int num = std::stoi(av[i]);
        if (num < 0)
            throw(std::invalid_argument("A number must be positive"));
        container.push_back(num);
    }

    return container;
}

template <template <typename, typename> class T>
void printContainer(const std::string& prefix, const T<int, std::allocator<int>>& container) {
    std::cout << prefix;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i];
        if (i + 1 < container.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

template <template <typename, typename> class T>
void sortFordJohnson(T<int, std::allocator<int>>& container) {
	if (container.size() <= 1) return;

	T<int, std::allocator<int>> min, max;

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

	T<int, std::allocator<int>> res = max;
	std::vector<size_t> jacobNumbers = generateJacobsthal(min.size());
	std::vector<bool> isInserted(min.size(), false);

	for (size_t j = 0; j < jacobNumbers.size() && jacobNumbers[j - 1] < min.size(); ++j) {
		size_t index = jacobNumbers[j];
		if (index < min.size()) {
			typename T<int, std::allocator<int>>::iterator pos = std::lower_bound(res.begin(), res.end(), min[index]);
			res.insert(pos, min[index]);
			isInserted[index] = true;
		}
	}
	for (size_t j = 0; j < min.size(); j++) {
		if (!isInserted[j]) {
			typename T<int, std::allocator<int>>::iterator pos = std::lower_bound(res.begin(), res.end(), min[j]);
			res.insert(pos, min[j]);
			isInserted[j] = true;
		}
	}
	container = res;
}