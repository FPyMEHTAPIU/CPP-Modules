#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		const unsigned int _N;
		std::vector<int> _vec;

	public:
		Span() = delete;
		Span(Span const& other) = delete;
		Span& operator=(Span const& other) = delete;
		~Span();
		Span(unsigned int n);

		void addNumber(int newNum);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		
		template <typename Iter>
		void addManyNumbers(Iter begin, Iter end) {
			try {
				size_t dist = std::distance(begin, end);
				if (_vec.size() + dist > _N)
					throw std::out_of_range("Vector's capacity isn't enough!");
				_vec.insert(_vec.end(), begin, end);
			} catch (const std::exception& e) {
				std::cout << "Exception: " << e.what() << std::endl;
			}
		}

		const std::vector<int>& getVec() const;
};