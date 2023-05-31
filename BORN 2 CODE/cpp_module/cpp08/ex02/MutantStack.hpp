#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack()
	{
	}
	MutantStack(const MutantStack &source)
	{
		*this = source;
	}
	MutantStack &operator = (const MutantStack &source)
	{
		*this = source;
		return (*this);
	}
	~MutantStack()
	{
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator cbegin()
	{
		return (this->c.cbegin());
	}
	const_iterator cend()
	{
		return (this->c.cend());
	}
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}
	reverse_iterator rend()
	{
		return (this->c.rend());
	}
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin()
	{
		return (this->c.crbegin());
	}
	const_reverse_iterator crend()
	{
		return (this->c.crend());
	}
};

#endif
