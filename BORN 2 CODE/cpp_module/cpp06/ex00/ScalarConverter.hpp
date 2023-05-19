#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <limits>
#include <exception>
#include <iomanip>

class ScalarConverter
{
private:
	static char c_value;
	static bool c_flag;
	static int i_value;
	static bool i_flag;
	static float f_value;
	static bool f_flag;
	static double d_value;
	static bool d_flag;
	ScalarConverter();
	ScalarConverter(const ScalarConverter &source);
	ScalarConverter &operator = (const ScalarConverter &source);
	~ScalarConverter();

public:
	static void convert(std::string str);
	static void check_valid(std::string str);
	static bool my_isnan(double num);
	static bool my_isinf(double num);
	class ImpossibleException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class NonDisplayableException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
