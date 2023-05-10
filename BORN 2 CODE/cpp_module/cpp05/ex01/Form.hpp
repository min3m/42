#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int _signGrade;
	const int _exeGrade;
	bool _sign;

public:
	Form();
	Form(const std::string &name, const int &s_grade, const int &e_grade);
	Form(const Form &source);
	Form &operator = (const Form &source);
	~Form();
	std::string getName() const;
	int getSignGrade() const;
	int getExeGrade() const;
	bool getSign() const;
	void beSigned(const Bureaucrat &someone);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};
std::ostream &operator << (std::ostream out, const Form &source);

#endif
