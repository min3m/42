#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
private:
	std::vector<unsigned int> v;

public:
	Span(unsigned int N);
	Span(const Span &source);
	Span &operator = (const Span &source);
	~Span();
	void addNumber(unsigned int N);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class AlreadyExistException : public std::exception
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
