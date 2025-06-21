#include "PmergeMe.hpp"

static std::vector<int> validateAdd(char **av) {
    std::vector<int> vec;

    for (int i = 0; av[i]; ++i) {
        int num = std::stoi(av[i]);
        if (num < 0)
            throw(std::invalid_argument("A number must be positive"));
        vec.push_back(num);
    }

    return vec;
}

void pmegreMe(char **av) {
    std::vector<int> vec = validateAdd(av);
}