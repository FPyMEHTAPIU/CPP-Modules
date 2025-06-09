#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> v = {10, 20, 30, 40};
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Found: " << *it << std::endl;

		easyfind(v, 100);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::list<int> lst = {1, 2, 3, 4, 5};
		std::list<int>::iterator it = easyfind(lst, 4);
		std::cout << "Found in list: " << *it << std::endl;

		easyfind(lst, -1);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}