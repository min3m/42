#include "MutantStack.hpp"
#include <iostream>
#include <list>

void test_list()
{
	std::list<int> list;
	std::cout << "-------List-------" << std::endl;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Top value : " << list.front() << std::endl;
	list.pop_back();
	std::cout << "Size : " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::cout << "Size : " << list.size() << std::endl;
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test_stack()
{
	MutantStack<int> mstack;
	std::cout << "-------Stack-------" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top value : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Size : " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	std::cout << "-------Stack s-------" << std::endl;
	std::cout << "Size : " << s.size() << std::endl;
	for (size_t i = 0; i < s.size() + 1; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
		i = 0;
	}
	std::cout << std::endl;
}

int main()
{
	test_stack();
	test_list();
	return 0;
}
