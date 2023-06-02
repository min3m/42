#include "RPN.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		RPN rpn;
		try
		{
			rpn.do_RPN(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	else
		std::cout << "Error" << std::endl;
	return (0);
}
