#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &s1, T &s2)
{
	T tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

template <typename T>
T min(T &s1, T &s2)
{
	if (s1 < s2)
		return (s1);
	return (s2);
}

template <typename T>
T max(T &s1, T &s2)
{
	if (s1 > s2)
		return (s1);
	return (s2);
}

#endif
