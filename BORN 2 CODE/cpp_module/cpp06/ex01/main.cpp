#include "Serializer.cpp"
#include <iostream>

int main()
{
	Data *ptr;
	Data *tmp;
	ptr = new Data;

	// tmp = Serializer::deserialize(Serializer::serialize(ptr));

	std::cout << "Before : " << ptr << std::endl;
	std::cout << "After : " << tmp << std::endl;
	return (0);
}
