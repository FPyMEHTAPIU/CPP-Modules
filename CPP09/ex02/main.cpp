#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac == 1) {
        std::cerr << "You must provide some arguments" << std::endl;
        return 1;
    }
    try {
        pmegreMe(av + 1, ac);
    } catch (std::invalid_argument&) {
        std::cerr << "Not a number provided" << std::endl;
    } catch (std::out_of_range&) {
        std::cerr << "Number is out of range" << std::endl;
    }catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}