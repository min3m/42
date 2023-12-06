#include <iostream>

class foo2
{
public:
	int *n;
public:
	foo2()
	{
		n = 1;
		std::cout << "Constructor" << std::endl;
	}
	foo2(int num)
	{
		n = num;
		std::cout << "Constructor" << std::endl;
	}
	~foo2()
	{
		std::cout << "Destructor" << std::endl;
	}
};


int main()
{

	{
		foo2 a(3);
		foo2 b(a);
		std::cout << a.n << '\n';
		std::cout << b.n << '\n';
	}
	std::cout << "end!\n";
	return (0);
}
