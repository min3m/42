#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void iter(T *array, std::size_t size, void (*add)(T&))
{
	for (std::size_t i = 0; i < size; i++)
		add(array[i]);
}

template <typename TT>
void add(TT &t)
{
	t += 1;
}

template <>
void add(std::string &t)
{
	t += "a";
}

#endif
