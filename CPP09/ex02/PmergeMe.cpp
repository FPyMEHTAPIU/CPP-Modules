#include "PmergeMe.hpp"

std::vector<std::string> split(const std::string& str, char del) {
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

std::vector<size_t> generateJacobsthal(size_t size) {
    std::vector<size_t> jacob;
    jacob.push_back(0);
    if (size == 1) return jacob;

    jacob.push_back(1);
    while (jacob.back() < size) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }
    return jacob;
}

void vectorSort(std::vector<int>& vec) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFordJohnson(vec);
    auto end = std::chrono::high_resolution_clock::now();
    printContainer("After: ", vec);
    auto duration = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void dequeSort(std::deque<int>& deq) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFordJohnson(deq);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << duration << " us" << std::endl;
}

void pmegreMe(char **av, int ac) {
    std::vector<int> vec = validateAdd<std::vector<int>>(av, ac);
    std::deque<int> deq = validateAdd<std::deque<int>>(av, ac);

    printContainer("Before: ", vec);
    vectorSort(vec);
    dequeSort(deq);
}