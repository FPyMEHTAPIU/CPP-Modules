#pragma once
#include "MutantStack.hpp"

template<typename T> MutantStack<T>::MutantStack(): std::stack<T>() {}
template<typename T> MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const& other): std::stack<T>(other) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}