#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <numeric>
#include <iostream>

class Span
{
private:
	std::vector<int> v;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &source);
	Span &operator = (const Span &source);
	~Span();
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class AlreadyFullException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class TooSmallException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};

#endif
