#include <iostream>
#include "foo.hpp"

void doSomething()
{
	std::cout << "HELLO " << std::endl;
	std::cout << foo::my_pi << " " << &foo::my_pi << std::endl;
}
