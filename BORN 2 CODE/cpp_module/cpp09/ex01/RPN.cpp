#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &source)
{
	*this = source;
}

RPN &RPN::operator = (const RPN &source)
{
	this->rpn = source.rpn;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::do_RPN(char *argv)
{
	std::string str(argv);
	std::string operations("+-*/");
	std::size_t found;

	for(std::size_t i = 0; i < str.size(); i++)
	{
		if (std::isspace(str[i]))
			continue ;
		if (std::isdigit(str[i]))
			rpn.push(str[i] - '0');
		else if(operations.find(str[i]) != std::string::npos)
		{
			found = operations.find(str[i]);
			if (rpn.empty())
				throw std::logic_error("Error");
			int num2 = rpn.top();
			rpn.pop();
			if (rpn.empty())
				throw std::logic_error("Error");
			int num1 = rpn.top();
			rpn.pop();
			calculate(num1, num2, found);
		}
		else
		{
			throw std::invalid_argument("Error");
		}
	}
	if (rpn.size() != 1)
		throw std::logic_error("Error");
	std::cout << rpn.top() << std::endl;
}

void RPN::calculate(int &num1, int &num2, size_t &found)
{
	switch (found)
	{
	case PLUS:
		rpn.push(num1 + num2);
		break;
	case MINUS:
		rpn.push(num1 - num2);
		break;
	case MULTIPLY:
		rpn.push(num1 * num2);
		break;
	default:
		if (num2 == 0)
			throw std::logic_error("Division by 0 is undefined behavior");
		else
			rpn.push(num1 / num2);
		break;
	}
}
