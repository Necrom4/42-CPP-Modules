#pragma once
#include <iostream>
#include <vector>

class Span
{
	private:
		Span();
		unsigned int _N;
		std::vector<int> _span;
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void			addNumber(unsigned int x);
		void			addNumber(std::vector<int>::iterator beginning, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;


	class limit: public std::exception
	{
		public:
			const char* what() const throw(){return "Already at N limit.";}
	};
	class span_excepetion: public std::exception
	{
		public:
			const char* what() const throw(){return "Not enough data to create span.";}
	};
};
