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
// #include <iostream>

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
// #// include <iostream>
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
// 정적멤버 변수 선언및 초기화 하는법! 정적 멤버 변수는 namespace영역에서 초기화 해줘야함! 왜냐 static은 이미 메모리에 올라가있지만
// 클라스는 아직 데이터가 올라가 있지 않기 때문에 메모리에 올린후 초기화 해줘야함! static const는 그냥 상수이기때문에 바로 초기화 ok
// #include <iostream>

// class Something
// {
// public:
// 	static int	value;
// };

// int Something::value = 1;

// int main()
// {
// 	Something	st1;
// 	Something	st2;

// 	std::cout << st1.value << std::endl;
// 	return (0);
// }
// 정적멤버 함수 사용법과 private statica멤버에 대한 접근을 어떻게하는지!
// #include <iostream>

// class Something
// {
// public:
// 	class _init
// 	{
// 	public:
// 		_init()
// 		{
// 			s_value = 9876;
// 		}
// 	};

// private:
// 	static int		s_value;
// 	int				m_value;
// 	static _init	s_init;

// public:
// 	static int	get_value()
// 	{
// 		return (s_value);
// 	}
// 	int	temp()
// 	{
// 		return (this->s_value);
// 	}
// };

// int Something::s_value = 1024;
// Something::_init Something::s_init;

// int main()
// {
// 	std::cout << Something::get_value() << std::endl;

// 	Something st1, st2;

// 	std::cout << st1.get_value() << std::endl;
// 	// std::cout << st1.s_value << std::endl;

// 	int	(Something::*fptr)() = &Something::temp;
// 	std::cout << (st1.*fptr)() << std::endl;

// 	int	(*fptr2)() = &Something::get_value;
// 	std::cout << (*fptr2)() << std::endl;

// 	return (0);
// }
//friend 선언하는 법과 사용법!
// #include <iostream>

// class A;

// class B
// {
// private:
// 	int	m_value = 2;

// public:
// 	void	doSomething ( A &a);
// };

// class A
// {
// private:
// 	int	m_value = 3;

// 	friend void	B::doSomething (A &a);
// };

// void	B::doSomething(A &a)
// {
// 		std::cout << a.m_value << std::endl;
// }

// int	main()
// {
// 	A	a;
// 	B	b;

// 	b.doSomething(a);
// 	return (0);
// }
// #include <iostream>

// class A
// {
// public:
// 	int	m_value;

// 	A(const int &input)
// 		:m_value(input)
// 	{ std::cout << "Constructor" << std::endl; }
// 	~A()
// 	{ std::cout << "Destructor" << std::endl; }
// 	void print()
// 	{
// 		std::cout << m_value << std::endl;
// 	}
// };

// int main()
// {
// 	A	a(2);
// 	a.print();
// 	a.print();
// 	A(2).print();
// 	return (0);
// }
// 익명객체 사용하는법!
// class Cents
// {
// private:
// 	int	m_value;
// public:
// 	Cents(int input) { m_value = input; }
// 	int getCents() const { return m_value; }
// };

// Cents	add(const Cents &c1, const Cents &c2)
// {
// 	return (Cents (c1.getCents() + c2.getCents()));
// }

// int main()
// {
// 	std::cout << add(Cents(6), Cents(8)).getCents() << std::endl;
// 	return (0);
// }
//연산자 오버로딩!!!
// #include <iostream>
// class Cents
// {
// private:
// 	int	m_value;
// public:
// 	Cents(int input) { m_value = input; }
// 	int getCents() const { return m_value; }

// 	friend Cents	operator + (const Cents &c1, const Cents &c2)
// 	{
// 		return (Cents (c1.getCents() + c2.getCents()));
// 	}
// };

// int main()
// {
// 	Cents	c1(6);
// 	Cents	c2(8);

// 	// std::cout << add(c1, c2).getCents() << std::endl;
// 	std::cout << (c1 + c2 + Cents(6)).getCents() << std::endl;
// 	return (0);
// }
// 입출력 오버로딩!
// #include <iostream>
// #include <fstream>

// class Point
// {
// private:
// 	double	_x, _y, _z;
// public:
// 	Point(double x = 0.0, double y = 0.0, double z = 0.0)
// 		: _x(x), _y(y), _z(z)
// 	{}
// 	double	get_x()	{ return (_x); }
// 	double	get_y()	{ return (_y); }
// 	double	get_z()	{ return (_z); }

// 	// void	print_point()
// 	// {
// 	// 	std::cout << _x << " " << _y << " " << _z << std::endl;
// 	// }
// 	friend std::istream& operator >> (std::istream &in, Point &point) // 참조자 꼭! 넣어주기! 안바뀐다 여기
// 	{
// 		in >> point._x >> point._y >> point._z;
// 		return (in);
// 	}
// 	friend std::ostream& operator << (std::ostream &out, const Point &point)
// 	{
// 		out << "[ " << point._x << " " << point._y << " " << point._z << " ]";
// 		return (out);
// 	}
// };

// int	main()
// {
// 	std::ofstream of("out.txt");
// 	Point	p1, p2;

// 	std::cin >> p1 >> p2;

// 	// p1.print_point(); 출력 오버로딩 하기 전
// 	// std::cout << " ";
// 	// p2.print_point();
// 	// std::cout << std::endl;

// 	std::cout << p1 << " " << p2 << std::endl;

// 	of.close();
// 	return (0);
// }
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Cents
// {
// private:
// 	int	m_value;
// public:
// 	Cents(int input = 0) { m_value = input; }
// 	int getCents() const { return m_value; }
// 	int& getCents() { return m_value; }

// 	// 단항연산자 오버로딩!
// 	// Cents operator - () const
// 	// {
// 	// 	return (-m_value);
// 	// }
// 	// bool operator ! () const
// 	// {
// 	// 	return ((m_value == 0) ? true : false);
// 	// }
// 	// == (비교 연산자 오버로딩!)
// 	// friend bool operator == (const Cents &c1, const Cents &c2)
// 	// {
// 	// 	return (c1.m_value == c2.m_value);
// 	// }
// 	// 크기 비교 연산자 오버로딩
// 	friend bool operator < (const Cents &c1, const Cents &c2)
// 	{
// 		return (c1.m_value < c2.m_value);
// 	}
// 	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
// 	{
// 		out << cents.m_value;
// 		return (out);
// 	}
// };

// int main()
// {
// 	// 크기 비교 연산자 오버로딩 해서 솔팅해보기!
// 	// vector<Cents> arr(20);

// 	// for (unsigned int i = 0; i < 20; i++)
// 	// 	arr[i].getCents() = i;
// 	// std::random_shuffle(begin(arr), end(arr));
// 	// for (auto &e : arr)
// 	// 	cout << e << " ";
// 	// cout <<endl;
// 	// std::sort(begin(arr), end(arr));
// 	// for (auto &e : arr)
// 	// 	cout << e << " ";
// 	// cout <<endl;
// 	// Cents	c1(6);
// 	// Cents	c2(6);

// 	// std::cout << c1 << std::endl;
// 	// std::cout << -c1 << std::endl;
// 	// std::cout << -Cents(-10) << std::endl;
// 	// std::cout << !c1 << " " << !c2 <<std::endl;
// 	// if (c1 == c2)
// 	// 	std::cout << "Equal" << std::endl;
// 	return (0);
// }
<<<<<<< HEAD
// 증감 연산자 오버로딩!
// #include <iostream>

// class Digit
// {
// private:
// 	int	_digit;
// public:
// 	Digit(int digit = 0) : _digit(digit) {}


// 	Digit& operator ++ ()
// 	{
// 		++_digit;
// 		return (*this);
// 	}
// 	Digit operator ++ (int)
// 	{
// 		Digit	temp(_digit);
// 		++(*this);
// 		return (temp);
// 	}

// 	friend std::ostream& operator << (std::ostream &out, const Digit &d)
// 	{
// 		out << d._digit;
// 		return (out);
// 	}
// };



// int	main()
// {
// 	Digit	d(10);

// 	std::cout << d << std::endl;
// 	std::cout << ++d << std::endl;
// 	std::cout << d++ << std::endl;
// 	std::cout << d << std::endl;
// 	return (0);
// }
//[]연산자 오버로딩하는 법!
// #include <iostream>
// #include <cassert>

// class List
// {
// private:
// 	int	arr[10];
// public:
// 	int &operator [](const int id)
// 	{
// 		assert(id >= 0);
// 		assert(id < 10);
// 		return arr[id];
// 	}
// 	const int &operator [](const int id) const
// 	{
// 		assert(id >= 0);
// 		assert(id < 10);
// 		return arr[id];
// 	}
// };

// int	main()
// {
// 	List my_list;

// 	my_list[4] = 10;
// 	std::cout << my_list[4] << std::endl;
// 	// my_list.set_item(3, 1);
// 	// std::cout << my_list.get_item(3) << std::endl;
// 	// my_list.get_list()[3] = 10;
// 	// std::cout << my_list.get_list()[3] << std::endl;
// 	return (0);
// }
// 형변환 overloading
// #include <iostream>

// class Cents
// {
// private:
// 	double	_value = 0;
// public:
// 	Cents(const double	input) : _value(input)
// 	{}
// 	// operator int ()
// 	// {
// 	// 	return(_value);
// 	// }
// 	operator double ()
// 	{
// 		return(_value);
// 	}
// };

// void	print_int(const double value)
// {
// 	std::cout << value << std::endl;
=======
#include <iostream>

class Digit
// {
private:
	int// 	_digit;
public:
	Digit(int digit = 0) : _digit(digit) {}


	Digit& operator ++ ()
	{
		++_digit;
		return (*this);
	}
	Digit operator ++ (int)
	{
		Digit	temp(_digit);
		++(*this);
		return (temp);
	}

	friend std::ostream& operator << (std::ostream &out, const Digit &d)
	{
		out << d._digit;
		return (out);
	}
};

// 	// std::cin >> My_string;
// 	std::cin.getline(My_string, 255);

// 	std::cout << My_string << std::endl;
// 	int	x;

// 	std::cin >> x;
// 	int	*arr = new int[x]{1,2,3,4,5};

// 	std::cout << sum_num(10, 12) << std::endl;
// 	return (0);
// }
//함수의 return value에 대해. 포인터나 레퍼런스로 리턴값을 받는건 주의! 잡혀있지 않은 메모리를 리턴받아 쓰레기 값이 저장되어 있을 수도 있음.
// #include <iostream>

// int	getValue(int x)
// {
// 	int	value = x * 5;
// 	return (value);
// }

// int	main()
// {
// 	int value = getValue(5);

// 	std::cout << value << std::endl;
// 	std::cout << value << std::endl;
// 	std::cout << value << std::endl;
// 	std::cout << value << std::endl;
// 	std::cout << value << std::endl;
// 	std::cout << value << std::endl;
// 	return (0);
// }
//함수 overloading에서 return type만 달라서는 다른 함수로 인식을 못함. parameter가 같으면 같은 함수로 인식! 즉 parameter가 다르고 존재해야 o ver loading 가능
// #include <iostream>

// auto	add(int x, int y)
// {
// 	return ((double )x + y);
// }

// double	add(double x, double y)
// {
// 	return (x + y);
>>>>>>> 150806eae2e595cf974f2c96b76bb31a2aec8b7e
// }

// int	main()
// {
<<<<<<< HEAD
// 	// Cents cents(7);
// 	Cents cents(7.3);
// 	double value = (double)cents;

// 	print_int(cents);
// 	return (0);
// }
//복사 생성자 사용법
// #include <iostream>
// #include <cassert>

// class Fraction
// {
// private:
// 	int	_numerator;
// 	int	_denominator;
// public:
// 	Fraction(int num = 0, int dem = 1)
// 		: _numerator(num), _denominator(dem)
// 	{ assert(dem != 0); }
// 	Fraction(const Fraction &fraction)
// 		: _numerator(fraction._numerator), _denominator(fraction._denominator)
// 	{ std::cout << "copy constrcutor call!" << std::endl; }
// 	friend std::ostream &operator << (std::ostream &out, const Fraction f)
// 	{
// 		out << f._numerator << "/" << f._denominator << std::endl;
// 		return (out);
// 	}
// };

// Fraction	dosomething()
// {
// 	Fraction	temp(3, 5);

// 	std::cout << &temp << std::endl;

// 	return (temp);
// }

// int main()
// {
// 	Fraction fration = dosomething();
// 	std::cout << &fration << std::endl;
// 	// std::cout << fration << std::endl;

// 	// Fraction f(fration);
// 	// std::cout << f;

// 	return (0);
// }
// 깊은 복사와 얕은 복사
// #include <iostream>
// #include <cassert>

// class My_string
// {
// // private:
// public:
// 	char	*_data = nullptr;
// 	int		_length = 0;
// public:
// 	My_string(const char *source = "")
// 	{
// 		assert(source);

// 		_length = std::strlen(source) + 1;
// 		_data = new char[_length];

// 		for (int i = 0; i < _length; i++)
// 			_data[i] = source[i];
// 		_data[_length - 1] = 0;
// 	}
// 	My_string(const My_string &source)
// 	{
// 		std::cout << "Copy constructor!!" << std::endl;
// 		_length = source._length;

// 		if (source._data != nullptr)
// 		{
// 			_data = new char[_length];
// 			for (int i = 0; i < _length; i++)
// 				_data[i] = source._data[i];
// 			_data[_length - 1] = 0;
// 		}
// 		else
// 			_data = nullptr;
// 	}
// 	My_string &operator = (const My_string &source)
// 	{
// 		std::cout << "Assignment operator!!" << std::endl;
// 		if (this == &source)
// 			return (*this);
// 		delete[] _data;
// 		_length = source._length;

// 		if (source._data != nullptr)
// 		{
// 			_data = new char[_length];
// 			for (int i = 0; i < _length; i++)
// 				_data[i] = source._data[i];
// 			_data[_length - 1] = 0;
// 		}
// 		else
// 			_data = nullptr;
// 	}
// 	char	*getString() { return _data; }
// 	~My_string()
// 	{
// 		delete[] _data;
// 	}
// };

// int main()
// {
// 	My_string	hello("hello");

// 	std::cout << (int *)hello._data << std::endl;
// 	std::cout << hello.getString() << std::endl;

// 	{
// 		My_string	copy = hello;
// 		std::cout << (int *)copy._data << std::endl;
// 		std::cout << copy.getString() << std::endl;
// 	}
// 	std::cout << hello.getString() << std::endl;
// 	return (0);
// }
//initializer list 오버로딩하는 법!
// #include <iostream>
// #include <cassert>
// #include <initializer_list>

// class IntArray
// {
// public:
// 	unsigned	_length = 0;
// 	int			*_data = nullptr;
// public:
// 	IntArray(unsigned input)
// 		: _length(input)
// 	{
// 		_data = new int[input];
// 	}
// 	IntArray(const std::initializer_list<int> &list)
// 		: IntArray(list.size())
// 	{
// 		int	count = 0;
// 		for (auto & e : list)
// 		{
// 			_data[count++] = e;
// 		}
// 		//list는 []참조 문자 사용 불가능!
// 	}
// 	~IntArray()
// 	{
// 		delete[] _data;
// 	};

// 	IntArray &operator = (const IntArray &source)
// 	{
// 		std::cout << "= operator!" << std::endl;
// 		if (this == &source)
// 			return (*this);
// 		if (_data)
// 			delete[] _data;
// 		if (source._data != nullptr)
// 		{
// 			_data = new int[_length];
// 			for (int i = 0; i < _length; i++)
// 			{
// 				_data[i] = source._data[i];
// 			}
// 		}
// 		else
// 			_data = nullptr;
// 		return (*this);
// 	}

// 	friend std::ostream &operator << (std::ostream &out, const IntArray &arr)
// 	{
// 		for(int i = 0; i < arr._length; i++)
// 		{
// 			out << arr._data[i] << " ";
// 		}
// 		out << std::endl;
// 		return(out);
// 	}
// };

// int	main()
// {
// 	int	arr1[5] = {1, 2, 3, 4, 5};
// 	int	*arr2 = new int[5]{1, 2, 3, 4, 5};

// 	auto	il = {1, 2, 3};
// 	IntArray int_array {1, 2, 6, 4, 5};
// 	std::cout << (int *)(int_array._data) << std::endl;
// 	IntArray int_array2 {1, 2, 3};
// 	int_array2 = int_array;
// 	std::cout << (int *)(int_array2._data) << std::endl;
// 	std::cout << int_array;
=======
// 	add(1, 2);
// 	add(3.0, 4.0);
// 	return (0);
// }
// parameter default값을 정해 줄 수 있다.
// #include <iostream>
// #include <string>

// void print(int x) {}
// void print(int x, int y ) { }

// // void	print(int x = 10, int y = 20 , int z = 30)
// // {
// // 	std::cout << x << " " << y << " " << z << std::endl;
// // }

// int	main()
// {
// 	// print(100);
// 	// print(100, 200);
// 	// print(100, 200, 300);
// 	// print();
// 	print(10);
// 	return (0);
// }
// 함수 포인터! 뒤에 예제 쫌 더 해보기
// #include <iostream>

// int func()
// {
// 	return (5);
// }

// int goo()
// {
// 	return (10);
// }

// int main()
// {
// 	int (*fptr)() = func;

// 	std::cout << fptr() << std::endl;
// 	fptr = goo;
// 	std::cout << fptr() << std::endl;
// }
// vector를 스택 즉 array처럼 사용하는 법!
// #include <iostream>
// #include <vector>

// void printstack(std::vector<int> &stack)
// {
// 	for (auto &i : stack)
// 		std::cout << i << " ";
// 	std::cout << std::endl;
// }

// int	main()
// {
// 	std::vector<int> stack = {1,2,3};

// 	stack.push_back(3);
// 	printstack(stack);
// 	stack.push_back(5);
// 	printstack(stack);
// 	stack.push_back(9);
// 	printstack(stack);
// 	stack.pop_back();
// 	printstack(stack);
// 	v.resize(2);
// 	v.reserve(100);
// 	std::cout << std::endl;
// 	std::cout << v.size() << " " << v.capacity() << std::endl;
// 	std::cout << v[2] << std::endl;
// 	int *ptr = v.data();
// 	std::cout << ptr[2] << std::endl;
// 	std::cout << v.at(2) << std::endl;
>>>>>>> 150806eae2e595cf974f2c96b76bb31a2aec8b7e
// 	return (0);
// }
