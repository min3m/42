#include <iostream>

int	sum_num(int x, int y)
{
	int	sum = x + y;
	return (sum);
}

int main()
{
	int	x = 2;
	int	y = x + 3;

	std::cout << sum_num(10, 12) << std::endl;
	return (0);
}
