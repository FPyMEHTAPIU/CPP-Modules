#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	try {
		// 1. Default constructor
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// 2. Constructor with size
		Array<int> intArray(5);
		std::cout << "intArray size: " << intArray.size() << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

		// 3. Modifying values
		for (unsigned int i = 0; i < intArray.size(); ++i)
			intArray[i] = i * 10;

		std::cout << "Modified intArray:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

		// 4. Copy constructor
		Array<int> copiedArray(intArray);
		std::cout << "Copied array:" << std::endl;
		for (unsigned int i = 0; i < copiedArray.size(); ++i)
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;

		// Modify copiedArray only
		copiedArray[0] = 999;
		std::cout << "After modifying copiedArray[0] = 999" << std::endl;
		std::cout << "copiedArray[0] = " << copiedArray[0] << std::endl;
		std::cout << "intArray[0] = " << intArray[0] << std::endl;

		// 5. Assignment operator
		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << "Assigned array:" << std::endl;
		for (unsigned int i = 0; i < assignedArray.size(); ++i)
			std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;

		// Modify assignedArray only
		assignedArray[1] = 777;
		std::cout << "After modifying assignedArray[1] = 777" << std::endl;
		std::cout << "assignedArray[1] = " << assignedArray[1] << std::endl;
		std::cout << "intArray[1] = " << intArray[1] << std::endl;

		// 6. Out-of-bounds test
		std::cout << "Accessing out-of-bounds index:" << std::endl;
		std::cout << intArray[100] << std::endl;  // must throw

	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// 7. Using array with std::string
	try {
		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";

		std::cout << "String array content:" << std::endl;
		for (unsigned int i = 0; i < strArray.size(); ++i)
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
