#include "ScalarConverter.hpp"

char ScalarConverter::c_value = 0;
int ScalarConverter::i_value = 0;
float ScalarConverter::f_value = 0.0f;
double ScalarConverter::d_value = 0.0;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	*this = source;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &source)
{
	static_cast<void>(source);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

char ScalarConverter::getCval()
{
	return (c_value);
}

int ScalarConverter::getIval()
{
	return (i_value);
}

float ScalarConverter::getFval()
{
	return (f_value);
}

double ScalarConverter::getDval()
{
	return (d_value);
}

void ScalarConverter::check_valid(std::string str)
{
	char *end;
	long tmp_l;
	double tmp_d;

	if (str.length() == 1 && isprint(str.front()) && !isdigit(str.front()))
	{
		c_value = str.front();
		i_value = static_cast<int>(c_value);
		f_value = static_cast<float>(c_value);
		d_value = static_cast<double>(c_value);
		return ;
	}
	tmp_l = std::strtol(str.c_str(), &end, 10);
	std::cout << tmp_l << " " << end << std::endl;
	tmp_d = std::strtod(str.c_str(), &end);
	std::cout << tmp_d << " " << end << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	check_valid(str);
	try
	{
		std::cout << "char: '" << ScalarConverter::getCval() << "'" << std::endl;
		std::cout << "int: " << ScalarConverter::getIval() << std::endl;
		std::cout << "float: " << ScalarConverter::getFval() << std::endl;
		std::cout << "double: " << ScalarConverter::getDval() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
