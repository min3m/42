// #include <iostream>
// #include <limits>

// int main()
// {
// 	double zero = 0.0;
// 	double posinf = 5.0 / zero;
// 	double neginf = -5.0 / zero;
// 	double nan = zero / zero;

// 	std::cout << sizeof(float) << std::endl;
// 	std::cout << sizeof(double) << std::endl;
// 	std::cout << sizeof(long double) << std::endl;

// 	std::cout << std::numeric_limits<float>::max() << std::endl;
// 	std::cout << std::numeric_limits<double>::max() << std::endl;
// 	std::cout << std::numeric_limits<long double>::max() << std::endl;

// 	std::cout << std::numeric_limits<float>::min() << std::endl;
// 	std::cout << std::numeric_limits<double>::min() << std::endl;
// 	std::cout << std::numeric_limits<long double>::min() << std::endl;

// 	std::cout << std::numeric_limits<float>::lowest() << std::endl;
// 	std::cout << std::numeric_limits<double>::lowest() << std::endl;
// 	std::cout << std::numeric_limits<long double>::lowest() << std::endl;

// 	// std::cout << posinf << " " << std::isinf(posinf) << std::endl;
// 	// std::cout << neginf << " " << std::isinf(neginf) << std::endl;
// 	// std::cout << nan << " " << std::isnan(nan) << std::endl;
// 	// std::cout << 1.0 << " " << std::isnan(1.0) << std::endl;
// 	// std::cout << 1.0 << " " << std::isinf(1.0) << std::endl;
// 	return (0);
// }
// #include <iostream>
// #include <limits>
// #include <bitset>
// int main()
// {
// 	unsigned char c = 0;

// 	std::cout << std::bitset<8>(c) << std::endl;

// 	// int a = 5, b = 10; 연산자
	// int z;

	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << ((b % 2 == 0) ? 0 : "odd" )<< std::endl;
	// char c(65);

	// std::cin >> c;
	// std::cout << c << " " << static_cast<int>(c) << std::endl;
	// std::cin >> c;
	// std::cout << c << " " << static_cast<int>(c) << std::endl;
	// std::cin >> c;
	// std::cout << c << " " << static_cast<int>(c) << std::endl;
	// std::cout << sizeof(char) << std::endl;
	// std::cout << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
	// std::cout << static_cast<int>(std::numeric_limits<char>::lowest()) << std::endl;
	// std::cout << -5 % -2 << std::endl;
// 	return (0);
// }
//네임스페이스 관련
// #include <iostream>

// namespace work1
// {
// 	int a = 1;
// 	void doSomething()
// 	{
// 		a += 5;
// 		// std::cout << a << std::endl;
// 	}
// }
// namespace work2
// {
// 	int a = 2;
// 	void doSomething()
// 	{
//  		a += 3;
// 		// std::cout << a << std::endl;
// 	}
// }
// int main()
// {
// 	work1::doSomething();
// 	// std::cout << "work1 " << work1::doSomething << std::endl;
// 	std::cout << work1::a << std::endl;
// 	// std::cout << "work2 " << work2::doSomething << std::endl;
// 	work2::doSomething();
// 	std::cout << work2::a << std::endl;
// }
// extern의 활용과 복사가 아닌 같은 전역변수를 쓰게하는 법
// #include <iostream>
// #include "foo.hpp"

// extern void doSomething();

// int main()
// {
// 	std::cout << foo::my_pi << " " << &foo::my_pi << std::endl;
// 	doSomething();
// }
// using문의 사용과 사용범위
// #include <iostream>

// namespace a{
// 	int val(123);
// }

// namespace b{
// 	int val(456);
// }

// int main()
// {
// 	using namespace std;


// 	cout << "HELLO" << endl;
// 	{
// 		using namespace a;
// 		cout << val << endl;
// 	}
// 	{
// 		using namespace b;
// 		cout << val << endl;
// 	}
// 	cout << val << endl;

// 	return (0);
// }
//auto의 사용
// #include <iostream>
// int main()
// {
// 	auto a = 'C';
// 	auto b = "HELLO~";
// 	auto c = 2.0f;
// 	auto d = 2.0;
// }
//cin 버퍼를 clear 해줘야한다!! 계속 남아있을 수도 있음
// #include <iostream>
// #include <string>
// #include <limits>

// int main()
// {
// 	std::cout << "Your age? : " ;
// 	int age;
// 	std::cin >> age;
// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// 	std::cout << "Your name? : ";
// 	std::string name;
// 	// std::cin >> name;
// 	std::getline(std::cin, name);

// 	// std::cout << "Your age? : " ;
// 	// std::string age;
// 	// std::cin >> age;
// 	// std::getline(std::cin, age);

// 	std::cout << name << " " << age << std::endl;
// 	return (0);
// }
//난수 생성하기
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// int	getRandNum(int min, int max)
// {
// 	static const double fraction = 1.0 / (RAND_MAX + 1.0);

// 	return (min + static_cast<int>((max - min + 1) * (std::rand() * fraction)));
// }

// int main()
// {
// 	// std::srand(5368);
// 	std::srand(static_cast<unsigned int>(std::time(0)));
// 	for (int i = 1; i <= 100; i++)
// 	{
// 		std::cout << getRandNum(3, 7) << " ";
// 		if (i % 5 == 0)
// 			std::cout << std::endl;
// 	}
// 	return (0);
// }
//cin 잘쓰는 방법
// #include <iostream>

// int	getNum()
// {
// 	int	x;
// 	while (true)
// 	{
// 		std::cin >> x;

// 		if (std::cin.fail())
// 		{
// 			std::cin.clear();
// 			std::cin.ignore(32767, '\n');
// 			std::cout << "Wrong Number" << std::endl;
// 		}
// 		else
// 		{
// 			std::cin.ignore(32767, '\n');
// 			return (x);
// 		}
// 	}
// }

// int	getOp()
// {
// 	char	op;
// 	std::cin >> op;
// 	std::cin.ignore(32767, '\n');
// 	return (op);
// }

// void	print_op(int x, char op, int y)
// {
// 	if (op == '+') std::cout << x + y << std::endl;
// 	else if (op == '-') std::cout << x - y << std::endl;
// 	else
// 		std::cout << "Invaild Operator" << std::endl;
// }

// int	main()
// {
// 	int		x = getNum();
// 	char	op = getOp();
// 	int		y = getNum();

// 	print_op(x, op, y);
// }
#include <iostream>

int main()
{
	char	My_string[255];

	// std::cin >> My_string;
	std::cin.getline(My_string, 255);

	std::cout << My_string << std::endl;

	return (0);
}
