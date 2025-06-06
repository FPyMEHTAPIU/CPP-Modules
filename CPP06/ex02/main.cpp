#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	Base* obj = nullptr;

	int num = std::rand();
	if (num % 3 == 0)
		obj = new A();
	else if (num % 3 == 1)
		obj = new B();
	else
		obj = new C();
	return obj;
}

void identify(Base* p) {
	A* typeA = dynamic_cast<A*>(p);
	if (typeA != nullptr) {
		std::cout << "The poiner's type is A!" << std::endl;
		return ;
	}
	B* typeB = dynamic_cast<B*>(p);
	if (typeB != nullptr) {
		std::cout << "The poiner's type is B!" << std::endl;
		return ;
	}
	C* typeC = dynamic_cast<C*>(p);
	if (typeC != nullptr) {
		std::cout << "The poiner's type is C!" << std::endl;
		return ;
	}
}


void identify(Base& p) {
	try {
		A& typeA = dynamic_cast<A&>(p);
		std::cout << &typeA << " reference's type is A!" << std::endl;
		return ;
	} catch (...) {}

	try {
		B& typeB = dynamic_cast<B&>(p);
		std::cout << &typeB << " reference's type is B!" << std::endl;
		return ;
	} catch (...) {}

	try {
		C& typeC = dynamic_cast<C&>(p);
		std::cout << &typeC << " reference's type is C!" << std::endl;
		return ;
	} catch (...) {}
}

int main() {
	std::srand(std::time(nullptr));
	for (int i = 0; i < 10; ++i) {
        std::cout << "=== Test " << i + 1 << " ===" << std::endl;
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
        std::cout << std::endl;
    }

	Base* ptr = nullptr;
    identify(ptr);
    identify(*ptr);
	if (ptr)
    	delete ptr;
    std::cout << std::endl;
}