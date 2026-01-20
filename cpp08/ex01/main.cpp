#include "Span.hpp"
#include <iostream>
#include <vector>

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

	// Test with 10000+ numbers using range of iterators
	Span big(10000);
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
		vec.push_back(i);
	big.addRange(vec.begin(), vec.end());

	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	return 0;
}
