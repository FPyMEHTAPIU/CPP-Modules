#include "Span.hpp"
#include <ctime>

namespace stq
{
    void println(std::string_view rem, const std::vector<int>& container)
    {
        std::cout << rem.substr(0, rem.size() - 2) << '[';
        bool first{true};
        for (const int x : container)
            std::cout << (first ? first = false, "" : ", ") << x;
        std::cout << "]\n";
    }
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span bigSpan(100);
    std::vector<int> vec;
    std::srand((std::time(0)));
    for (int i = 0; i < 100; ++i) {
        vec.push_back(std::rand() / 100000);
    }
    bigSpan.addManyNumbers(vec.begin(), vec.end());
	stq::println("big span {}", bigSpan.getVec());
	std::cout << bigSpan.shortestSpan() << std::endl;
	std::cout << bigSpan.longestSpan() << std::endl;
	return 0;
}