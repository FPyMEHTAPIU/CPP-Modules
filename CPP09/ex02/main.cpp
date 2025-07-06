#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac == 1) {
        std::cerr << "You must provide some arguments" << std::endl;
        return 1;
    }
    try {
        pmegreMe(av + 1, ac);
    } catch (...) {
        std::cerr << "Error" << std::endl;
    }
    
    return 0;
}