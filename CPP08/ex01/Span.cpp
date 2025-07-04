#include "Span.hpp"

Span::~Span() {}
Span::Span(unsigned int n): _N(n) {
	_vec.reserve(_N);
}

void Span::addNumber(int newNum) {
	try {
		if (_vec.size() == _N)
			throw std::out_of_range("Vector's max capacity reached!");
		_vec.push_back(newNum);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

unsigned int Span::shortestSpan() const {
	unsigned int min = 0;

	if (_vec.size() <= 1)
		throw std::length_error("Not enough size to find the span");
	std::vector<int> copy = _vec;
	
	std::sort(copy.begin(), copy.end());
	for (size_t i = 1; i < copy.size(); ++i) {
		unsigned int diff = std::abs(copy[i]) - std::abs(copy[i - 1]);
		if (min == 0)
			min = diff;
		else if (diff > 0 && diff < min)
			min = diff;
	}
	return min;
}

unsigned int Span::longestSpan() const {
	if (_vec.size() <= 1)
		throw std::length_error("Not enough size to find the span");
	std::vector<int> copy = _vec;
	
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

const std::vector<int>& Span::getVec() const {
	return _vec;
}