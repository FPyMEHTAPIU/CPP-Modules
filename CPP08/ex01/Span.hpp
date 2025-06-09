#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		const unsigned int _N;
		std::vector<int> vec;

	public:
		Span() = delete;
		Span(Span const& other) = delete;
		Span& operator=(Span const& other) = delete;
		~Span();
		Span(unsigned int n);

		void addNumber(int newNum);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void addManyNumbers();
};