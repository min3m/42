#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &s1, T &s2)
{
	T tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
};



#endif
