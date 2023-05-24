#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <exception>
#include <vector>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Easyfind can't find value in this container");
	}
};


template <typename T>
typename T::iterator easyfind(T &source, int value)
{
	typename T::iterator iter = std::find(source.begin(), source.end(), value);

	if (iter == source.end())
		throw NotFoundException();
	return (iter);
}

#endif
