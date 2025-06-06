#pragma once
#include "Array.hpp"

template<typename T> Array<T>::Array(): _array(nullptr), _arrSize(0) {}

template<typename T> Array<T>::Array(unsigned int n) {
	try {
		_arrSize = n;
		_array = new T[_arrSize];
	} catch (...) {
		std::cerr << "Allocation error" << std::endl;
	}
}

template<typename T> Array<T>::Array(Array const& other): _array(nullptr), _arrSize(0) {
	*this = other;
}

template<typename T> Array<T>& Array<T>::operator=(Array const& other) {
	if (this != &other) {
		try {
			delete[] _array;
			_arrSize = other._arrSize;
			_array = new T[_arrSize];
			for (unsigned int i = 0; i < _arrSize; ++i) {
				_array[i] = other._array[i];
			}
		} catch (...) {
			std::cerr << "Allocation error" << std::endl;
		}

	}
	return *this;
}

template<typename T> Array<T>::~Array() {
	delete[] _array;
}

template<typename T> T& Array<T>::operator[](unsigned int index) {
	if (index >= _arrSize)
		throw(std::out_of_range("Index out of bounds"));
	return _array[index];
}

template<typename T> unsigned int Array<T>::size() const {
	return _arrSize;
}