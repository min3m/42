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
// #include <iostream>
// int main()
// {
// 	char	My_string[255];

// 	// std::cin >> My_string;
// 	std::cin.getline(My_string, 255);

// 	std::cout << My_string << std::endl;
// 	int	x;

// 	std::cin >> x;
// 	int	*arr = new int[x]{1,2,3,4,5};

// 	for (int i = 0; i < x ; i++)
// 		std::cout << arr[i] << std::endl;
// 	delete[] arr;
// 	for (int i = 0; i < x ; i++)
// 		std::cout << arr[i] << std::endl;
// 	return (0);
// }
// 참조자의 사용
// #include <iostream>
// void	doSomething(const int &num)
// {
// 	// num = 10;
// 	std::cout << num << std::endl;
// 	std::cout << &num << std::endl;
// }

// int	main()
// {
// 	int	a = 5;
// 	int &val = a;
// 	int *ptr = &a;

// 	std::cout << *ptr << std::endl;
// 	std::cout << val << std::endl;
// 	std::cout << &val << std::endl;

// 	doSomething(a);
// 	std::cout << a << std::endl;
// 	std::cout << val << std::endl;
// 	return (0);
// }
//std::array사용법
// #include <iostream>
// #include <limits>
// #include <algorithm>

// int main()
// {
// 	int array[] = {0,1,1,2,3,5,300,13,21,34,55,89};
// 	int max_n;

// 	max_n = std::numeric_limits<int>::lowest();
// 	for (const int &n : array)
// 		max_n = std::max(max_n, n);

// 	std::cout << max_n << std::endl;
// 	// for (int number : array)
// 	// 	std::cout << number << std::endl;
// 	return (0);
// }
//recursive 함수 / 피보나치
// #include <iostream>

// int	fibonacci(int count)
// {
// 	if (count <= 1)
// 		return (0);
// 	else if (count == 2)
// 		return (1);
// 	else
// 		return fibonacci(count - 1) + fibonacci(count - 2);
// }

// int	main()
// {
// 	for (int i = 1; i <= 11; i++)
// 		std::cout << fibonacci(i) << std::endl;
// 	return (0);
// }
// 캡슐화!!! 하는 법과 이유!
// #include <iostream>

// class Date
// {
// private:
// 	int	_date;
// 	int	_month;
// 	int	_year;

// public:
// 	void	set_date(const int &s_date, const int &s_month, const int &s_year)
// 	{
// 		_date = s_date;
// 		_month = s_month;
// 		_year = s_year;
// 	}
// 	const int	&get_day()
// 	{
// 		return _date;
// 	}
// 	const int	&get_month()
// 	{
// 		return _month;
// 	}
// 	void	Copy(const Date &orignal)
// 	{
// 		_date = orignal._date;
// 		_month = orignal._month;
// 		_year = orignal._year;
// 	}
// };

// int	main()
// {
// 	Date	today;
// 	// today.date = 25;
// 	// today.month = 8;
// 	// today.year = 2023;

// 	today.set_date(25, 8, 2024);

// 	std::cout << today.get_day() << std::endl;

// 	Date	copy;

// 	copy.Copy(today);
// 	std::cout << "At copy \n" << copy.get_day() << std::endl;
// 	std::cout << copy.get_month() << std::endl;
// 	return (0);
// }
// #include <iostream>

// class Fraction
// {
// private:
// 	int	_bunja;
// 	int	_bunmo;

// public:
// 	Fraction(const int &bunja_in = 2, const int &bunmo_in = 3)
// 	{
// 		_bunja = bunja_in;
// 		_bunmo = bunmo_in;
// 	}
// 	void	print()
// 	{
// 		std::cout << _bunja << " \\ " << _bunmo << std::endl;
// 	}
// };

// int	main()
// {
// 	Fraction	frac{ 3 , 4 };

// 	frac.print();
// 	return (0);
// }

// Constructor 사용법!
// #include <iostream>

// class Second
// {
// public:
// 	Second()
// 	{
// 		std::cout << "Second constructor" << std::endl;
// 	}
// };

// class First
// {
// private:
// 	Second sec;
// public:
// 	First()
// 	{
// 		std::cout << "First constructor" << std::endl;
// 	}
// };

// int main()
// {
// 	First fir;
// 	return (0);
// }
// 생성자 멤버의 초기화 목록 사용하는 법!
// #include <iostream>

// class B
// {
// private:
// 	int	m_b;
// public:
// 	B(const int &m_b_in)
// 		:m_b(m_b_in)
// 	{}
// 	void	print_b()
// 	{
// 		std::cout << m_b << std::endl;
// 	}
// };

// class Something
// {
// private:
// 	int		m_i = 1;
// 	double	m_d = 4.2;
// 	char	m_c = 'B';
// 	int		m_arr[5] = {6,7,8,9,10};
// 	B		m_b;
// public:
// 	Something()
// 		: m_i{1}, m_d{3.14}, m_c{'A'}, m_arr{1,2,3,4,5}, m_b(m_i - 1)
// 		{
// 			m_i *= 3;
// 			m_d *= 3;
// 			m_c += 3;
// 		}
// 	void	print_something()
// 	{
// 		std::cout << m_i << " " << m_d << " " << m_c << " " << std::endl;
// 		for (auto &e : m_arr)
// 			std::cout << e << " ";
// 		std::cout << std::endl;
// 	}
// };

// int main()
// {
// 	Something	i;
// 	B			j{0};

// 	i.print_something();
// 	j.print_b();
// 	return (0);
// }
// 소멸자에 대한 기본 사용 법!
// #include <iostream>

// class IntArray
// {
// private:
// 	int	*m_arr = nullptr;
// 	int	m_length = 0;
// public:
// 	IntArray(const int &length_in)
// 	{
// 		m_length = length_in;
// 		m_arr = new int[m_length];
// 		// std::cout << "Constructor" << std::endl;
// 	}
// 	~IntArray()
// 	{
// 		if (m_arr != nullptr)
// 			delete[] m_arr;
// 		// std::cout << "Destructor" << std::endl;
// 	}
// };


// int	main()
// {
// 	while (1)
// 	{
// 		IntArray	a(10000);
// 		// system("leaks a.out");
// 	}
// 	return (0);
// }
