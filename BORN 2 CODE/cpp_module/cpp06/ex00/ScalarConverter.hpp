#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <exception>

class ScalarConverter
{
private:
	static char c_value;
	static int i_value;
	static float f_value;
	static double d_value;

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &source);
	ScalarConverter &operator = (const ScalarConverter &source);
	~ScalarConverter();
	static char getCval();
	static int getIval();
	static float getFval();
	static double getDval();
	static void convert(std::string str);
	static void check_valid(std::string str);
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
