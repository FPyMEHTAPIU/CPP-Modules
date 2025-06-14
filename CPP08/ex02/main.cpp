#include <iostream>
#include "MutantStack.hpp"
#include <list>

void test_mutantstack() {
	std::cout << "=== MutantStack Test ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Contents:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Copy construction
	std::stack<int> s(mstack);
	std::cout << "Copied std::stack top: " << s.top() << std::endl;
}

void test_list_equivalent() {
	std::cout << "\n=== std::list Equivalent Test ===" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;

	lst.pop_back();
	std::cout << "Size after pop_back: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	std::cout << "Contents:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	test_mutantstack();
	test_list_equivalent();
	return 0;
}
