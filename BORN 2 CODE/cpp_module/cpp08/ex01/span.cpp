#include "span.hpp"

Span::Span(unsigned int N)
{
	this->v.push_back(N);
}

Span::Span(const Span &source)
{
}

Span &Span::operator = (const Span &source)
{
}

Span::~Span()
{
}
