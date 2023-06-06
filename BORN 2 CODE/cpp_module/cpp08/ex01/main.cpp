#include "span.hpp"

int main()
{
	Span sp1 = Span(5);
	Span sp2 = Span(100);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	sp2.addRandomNum();
	sp2.printVector();
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return (0);
}
