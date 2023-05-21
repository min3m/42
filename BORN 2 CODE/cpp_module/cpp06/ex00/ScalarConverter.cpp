#include "ScalarConverter.hpp"

char ScalarConverter::c_value = 0;
bool ScalarConverter::c_flag = false;
int ScalarConverter::i_value = 0;
bool ScalarConverter::i_flag = false;
float ScalarConverter::f_value = 0.0f;
bool ScalarConverter::f_flag = false;
double ScalarConverter::d_value = 0.0;
bool ScalarConverter::d_flag = false;

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

bool ScalarConverter::my_isnan(double num)
{
	return (num != num);
}

bool ScalarConverter::my_isinf(double num)
{
	return (num != 0 && num * 2 == num);
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
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
	else
	{
		tmp_l = std::strtol(str.c_str(), &end, 10);
		if (errno != ERANGE && !(*end) && tmp_l >= INT_MIN && tmp_l <= INT_MAX)
		{
			i_value = static_cast<int>(tmp_l);
			if (i_value <= CHAR_MIN || i_value >= CHAR_MAX)
				c_flag = true;
			c_value = static_cast<char>(i_value);
			f_value = static_cast<float>(i_value);
			d_value = static_cast<double>(i_value);
			return ;
		}
		tmp_d = std::strtod(str.c_str(), &end);
		if (errno != ERANGE && *end == 'f' && !(*(end + 1))
			&& tmp_d >= std::numeric_limits<float>::min() && tmp_d <= std::numeric_limits<float>::max())
		{
			f_value = static_cast<float>(tmp_d);
			d_value = static_cast<double>(f_value);
			if (tmp_l < INT_MIN || tmp_l > INT_MAX || my_isnan(tmp_d) || my_isinf(tmp_d))
				i_flag = true;
			i_value = static_cast<int>(f_value);
			if (tmp_l < CHAR_MIN || tmp_l > CHAR_MAX || my_isnan(tmp_d) || my_isinf(tmp_d))
				c_flag = true;
			c_value = static_cast<char>(f_value);
			return ;
		}
		else if (errno != ERANGE && !(*end))
		{
			d_value = tmp_d;
			if (!my_isinf(tmp_d) && (tmp_d < std::numeric_limits<float>::min() || tmp_d > std::numeric_limits<float>::max()))
				f_flag =true;
			f_value = static_cast<float>(d_value);
			if (tmp_l < INT_MIN || tmp_l > INT_MAX || my_isnan(tmp_d) || my_isinf(tmp_d))
				i_flag = true;
			i_value = static_cast<int>(d_value);
			if (tmp_l < CHAR_MIN || tmp_l > CHAR_MAX || my_isnan(tmp_d) || my_isinf(tmp_d))
				c_flag = true;
			c_value = static_cast<char>(d_value);
			return ;
		}
		else
		{
			c_flag = true;
			i_flag = true;
			f_flag = true;
			d_flag = true;
		}
	}
}

void ScalarConverter::convert(std::string str)
{
	check_valid(str);
	try
	{
		if(c_flag)
			throw (ScalarConverter::ImpossibleException());
		else if (isprint(c_value))
			std::cout << "char: '" << c_value << "'" << std::endl;
		else
			throw (ScalarConverter::NonDisplayableException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if(i_flag)
			throw (ScalarConverter::ImpossibleException());
		else
			std::cout << "int: " << i_value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if(f_flag)
			throw (ScalarConverter::ImpossibleException());
		else
		{
			std::cout << "float: ";
			if (my_isinf(f_value) && powf(f_value, 2) == f_value)
				std::cout << "+";
			if (abs(f_value - static_cast<int>(f_value)) < 1e-6)
				std::cout << f_value << ".0";
			else
				std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f_value;
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if(d_flag)
			throw (ScalarConverter::ImpossibleException());
		else
		{
			std::cout << "double: ";
			if (my_isinf(d_value) && pow(d_value, 2) == d_value)
				std::cout << "+";
			if (abs(d_value - static_cast<int>(d_value)) < 1e-12)
				std::cout << d_value << ".0";
			else
				std::cout << std::setprecision(std::numeric_limits<double>::digits10) << d_value;
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
