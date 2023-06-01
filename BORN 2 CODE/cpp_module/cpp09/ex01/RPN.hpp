#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
private:
	std::stack<int> stack;

public:
	RPN();
	RPN(const RPN &source);
	RPN &operator = (const RPN &source);
	~RPN();
	void do_RPN(char *argv);
	void calculate(int num1, int num2, std::size_t find);
};

#endif
