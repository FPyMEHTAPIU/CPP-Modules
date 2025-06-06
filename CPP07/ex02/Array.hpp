#pragma once
#include <iostream>

template<typename T>
class Array {
	private:
		T* _array;
		unsigned int _arrSize;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const& other);
		Array& operator=(Array const& other);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"