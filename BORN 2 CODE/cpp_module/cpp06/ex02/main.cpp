#include "Base.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

Base* generate(void)
{
	srand((unsigned int)time(NULL));
	int num = rand();
	switch (num % 3)
	{
	case 0:
		std::cout << "is A" << std::endl;
		return (dynamic_cast<Base *>(new A));
	case 1:
		std::cout << "is B" << std::endl;
		return (dynamic_cast<Base *>(new B));
	case 2:
		std::cout << "is C" << std::endl;
		return (dynamic_cast<Base *>(new C));
	default:
		break;
	}
	return (NULL);
}

void identify(Base* P)
{
	A *a = dynamic_cast<A *>(P);
	B *b = dynamic_cast<B *>(P);
	C *c = dynamic_cast<C *>(P);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}

void identify(Base& P)
{
	try
	{
		A &a = dynamic_cast<A &>(P);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B &>(P);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C &>(P);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{}
}

int main()
{
	std::cout << "P1 ";
	Base *P1 = generate();
	sleep(1);
	std::cout << "P2 ";
	Base &P2 = *generate();

	std::cout << "Identify P1 : ";
	identify(P1);
	std::cout << "Identify P2 : ";
	identify(P2);

	delete P1;
	delete &P2;
	return (0);
}
