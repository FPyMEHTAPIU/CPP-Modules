#include "whatever.hpp"
#include <iostream>
#include <string>

struct Point {
	int x;
	int y;

	bool operator<(const Point& other) const {
		return x*x + y*y < other.x*other.x + other.y*other.y;
	}

	bool operator>(const Point& other) const {
		return x*x + y*y > other.x*other.x + other.y*other.y;
	}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

int main() {
	std::cout << "Test 1: int" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "\nTest 2: string" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << "\nTest 3: double" << std::endl;
	double x = 42.42;
	double y = -15.15;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << "\nTest 4: char" << std::endl;
	char e = 'A';
	char f = 'Z';
	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	std::cout << "\nTest 5: struct Point" << std::endl;
	Point p1 = {1, 2};
	Point p2 = {3, 1};
	std::cout << "Before swap: p1 = " << p1 << ", p2 = " << p2 << std::endl;
	::swap(p1, p2);
	std::cout << "After swap: p1 = " << p1 << ", p2 = " << p2 << std::endl;
	std::cout << "min(p1, p2) = " << ::min(p1, p2) << std::endl;
	std::cout << "max(p1, p2) = " << ::max(p1, p2) << std::endl;

	return 0;
}
