#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		using iterator = typename std::deque<T>::iterator;
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const& other);
		MutantStack& operator=(MutantStack const& other);
	
		iterator begin();
		iterator end();
};