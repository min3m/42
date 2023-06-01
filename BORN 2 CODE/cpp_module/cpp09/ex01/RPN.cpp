#include "RPN.hpp"

#include <iostream>

RPN::RPN()
{
}

RPN::RPN(const RPN &source)
{
	*this = source;
}

RPN &RPN::operator = (const RPN &source)
{
	this->stack = source.stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::do_RPN(char *argv)
{
	std::stack<int> oper;
	std::string str(argv);
	std::string operations("+-*/");
	std::size_t find;

	for(std::size_t i = 0; i < str.size(); i++)
	{
		if (std::isspace(str[i]))
			continue ;
		if (std::isdigit(str[i]))
			stack.push(str[i] - '0');
		else if(operations.find(str[i]) != std::string::npos)
		{
			find = operations.find(str[i]);
		}
		else
		{
			throw std::string("Error");
		}
	}
}
