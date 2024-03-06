#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N): _N(N){}

Span::Span(const Span &copy){*this = copy;}

Span &Span::operator=(const Span &copy)
{
	_span = copy._span;
	_N = copy._N;
	return *this;
}

Span::~Span(){}

void			Span::addNumber(unsigned int x)
{
	if (_span.size() == _N)
		throw Span::limit();
	_span.push_back(x);
}

void			Span::addNumber(std::vector<int>::iterator beginning, std::vector<int>::iterator end)
{
	if (end - beginning > _N)
		throw Span::limit();
	_span.insert(_span.end(), beginning, end);
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int>	copy(_span);

	if (_span.size() <= 1)
		throw Span::span_excepetion();
	std::sort(copy.begin(),copy.end());
	int	shortest_span = copy[1] - copy[0];
	for (unsigned long i = 1; i < copy.size(); i++)
		if (copy[i] - copy[i - 1] < shortest_span)
			shortest_span = copy[i] - copy[i - 1];
	return shortest_span;
}

unsigned int	Span::longestSpan() const
{
	std::vector<int>	copy(_span);

	if (_span.size() <= 1)
		throw Span::span_excepetion();
	std::sort(copy.begin(),copy.end());
	return copy[copy.size() - 1] - copy[0];
}
