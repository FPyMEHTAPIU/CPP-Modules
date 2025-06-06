#include "iter.hpp"

template <typename T>
void printElement(T& elem) {
	std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
	++elem;
}

void addExclamation(std::string& s) {
	s += "!";
}

int main() {
	std::cout << "Int test\n";
	int arr1[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(arr1, 5, printElement<int>);
	std::cout << "\nAfter increment: ";
	iter(arr1, 5, increment<int>);
	iter(arr1, 5, printElement<int>);
	std::cout << "\n";

	std::cout << "String test\n";
	std::string arr2[] = {"hello", "world"};
	std::cout << "Original string array: ";
	iter(arr2, 2, printElement<std::string>);
	std::cout << "\nAfter addExclamation: ";
	iter(arr2, 2, addExclamation);
	iter(arr2, 2, printElement<std::string>);
	std::cout << "\n";

	std::cout << "String test\n";
	char arr3[] = {'a', 'b', 'c'};
	std::cout << "Original char array: ";
	iter(arr3, 3, printElement<char>);
	iter(arr3, 3, increment<char>);
	std::cout << "\nIncremented char array: ";
	iter(arr3, 3, printElement<char>);
	std::cout << std::endl;

	return 0;
}
