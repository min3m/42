#include <iostream>

// struct Mystruct
// {
// 	int array[5] = {9,7,6,5,4};
// 	double x = 7.0;
// 	double y = 3.0;
// };

// void	sum_num(Mystruct *ms)
// {
// 	std::cout << std::endl;
// 	std::cout << (*ms).array[0] << std::endl;
// 	std::cout << (*ms).array[1] << std::endl;
// 	std::cout << sizeof((*ms).array) << std::endl;
// 	std::cout << sizeof(ms) << std::endl;
// }

// int main()
// {
// 	int *num;
// 	int a;
// 	const char *name = "Hi";
// 	const char *name2 = "Hi";

// 	int *ptr;
// 	long l;
// 	long long ll;
// 	Mystruct ms;

// 	a = 5;
// 	num = &a;
// 	std::cout << num << std::endl;
// 	std::cout << (uintptr_t)name << std::endl;
// 	std::cout << (uintptr_t)name2 << std::endl;
// 	std::cout << ms.array[0] << std::endl;
// 	std::cout << ms.array[1] << std::endl;
// 	std::cout << sizeof(ms.array) << std::endl;
// 	std::cout << sizeof(ms) << std::endl;
// 	std::cout << sizeof(ptr) << std::endl;
// 	sum_num(&ms);
// 	return (0);
// }
int main()
{
	int	x;

	std::cin >> x;
	int	*arr = new int[x]{1,2,3,4,5};

	for (int i = 0; i < x ; i++)
		std::cout << arr[i] << std::endl;
	delete[] arr;
	for (int i = 0; i < x ; i++)
		std::cout << arr[i] << std::endl;
	return (0);
}
