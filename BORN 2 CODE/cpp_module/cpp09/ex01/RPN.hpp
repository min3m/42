#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2

class RPN
{
private:
	std::stack<int> rpn;

public:
	RPN();
	RPN(const RPN &source);
	RPN &operator = (const RPN &source);
	~RPN();
	void do_RPN(char *argv);
	void calculate(int &num1, int &num2, std::size_t &found);
};

#endif
