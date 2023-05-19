#include "iter.hpp"


int main()
{
	std::string s = "Ji";
	std::string str[3] = {"Hello", "my", "name"};
	int i[6] = {1, 2, 3, 4, 5, 6};
	char c[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	double d[6] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};

	iter(str, 3, add);
	iter(i, 6, add);
	iter(c, 6, add);
	iter(d, 6, add);

	for (int n = 0; n < 3; n++)
		std::cout << str[n] << " ";
	std::cout << std::endl;
	for (int n = 0; n < 6; n++)
		std::cout << i[n] << " ";
	std::cout << std::endl;
	for (int n = 0; n < 6; n++)
		std::cout << c[n] << " ";
	std::cout << std::endl;
	for (int n = 0; n < 6; n++)
		std::cout << d[n] << " ";
	std::cout << std::endl;
	return (0);
}
