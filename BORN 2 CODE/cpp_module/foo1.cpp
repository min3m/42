#include <iostream>
#include <string>

int main()
{
	const std::string str1("abcedf");
	const std::string str2;

	static_cast<std::string>(str2) = str1;
	std::cout << str2 << std::endl;
	return (0);
}
