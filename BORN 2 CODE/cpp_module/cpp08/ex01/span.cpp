#include "span.hpp"

Span::Span()
{
	this->v.reserve(0);
}

Span::Span(unsigned int N)
{
	this->v.reserve(N);
}

Span::Span(const Span &source)
{
	*this = source;
}

Span &Span::operator = (const Span &source)
{
	this->v = source.v;
	return (*this);
}

Span::~Span()
{
}

void makeRandomNum(int &num)
{
	num = std::rand() % 10000;
}

void Span::addRandomNum()
{
	std::srand(static_cast<unsigned int>(time(NULL)));
	v.resize(v.capacity());
	std::for_each(v.begin(), v.end(), makeRandomNum);
}

void Span::addNumber(int num)
{
	if (v.size() == v.capacity())
		throw AlreadyFullException();
	this->v.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (v.size() < 2)
		throw TooSmallException();
	std::vector<int> tmp;
	tmp = v;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return (*std::min_element(tmp.begin() + 1, tmp.end()));
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2)
		throw TooSmallException();
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()));
}

void Span::printVector()
{
	std::vector<int>::iterator itr;
	std::cout << "Vector : ";
	for (itr = v.begin(); itr != v.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

const char *Span::TooSmallException::what() const throw()
{
	return ("Vector size is too small");
}

const char *Span::AlreadyFullException::what() const throw()
{
	return ("Vector is already full");
}
