#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}
	try
	{
		std::vector<int>::iterator find;
		find = easyfind(v, 5);
		std::cout << *find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator find;
		find = easyfind(l, 9);
		std::cout << *find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator find;
		find = easyfind(d, 11);
		std::cout << *find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
