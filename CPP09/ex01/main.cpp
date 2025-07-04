#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Provide only one argument!" << std::endl;
        return 1;
    }
    try {
        RPN(av[1]);
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}