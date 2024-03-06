#include "Span.hpp"
//int main() { Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//
//	return 0;
//}
//
//
int main()
{
	std::cout << "[NORMAL TEST]" << std::endl;
	try
	{
		Span a = Span(5);

		a.addNumber(6);
		a.addNumber(2);
		a.addNumber(17);
		a.addNumber(0);
		a.addNumber(6);

		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	}
	catch (std::exception &x){std::cerr << "Error: " << x.what() << std::endl;}
	std::cout << "[FULL ARRAY TEST]" << std::endl;
	try
	{
		Span a = Span(5);

		a.addNumber(6);
		a.addNumber(2);
		a.addNumber(17);
		a.addNumber(0);
		a.addNumber(6);
		a.addNumber(5);

		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	}
	catch (std::exception &x){std::cerr << "Error: " << x.what() << std::endl;}
	std::cout << "[EMPTY ARRAY TEST]" << std::endl;
	try
	{
		Span a = Span(5);

		a.addNumber(6);

		int	shortest_span_val = a.shortestSpan();
		int	longest_span_val = a.longestSpan();
		std::cout << "Shortest span: " << shortest_span_val << std::endl;
		std::cout << "Longest span: " << longest_span_val << std::endl;
	}
	catch (std::exception &x){std::cerr << "Error: " << x.what() << std::endl;}
	std::cout << "[HUGE ARRAY TEST]" << std::endl;
	try
	{
		std::vector<int>	huge(1000000);
		for (int i = 1; i <= 1000000; i++)
			huge[i] = i;

		Span a = Span(1000000);

		a.addNumber(huge.begin(), huge.end());

		int	shortest_span_val = a.shortestSpan();
		int	longest_span_val = a.longestSpan();
		std::cout << "Shortest span: " << shortest_span_val << std::endl;
		std::cout << "Longest span: " << longest_span_val << std::endl;
	}
	catch (std::exception &x){std::cerr << "Error: " << x.what() << std::endl;}

	return 0;
}
