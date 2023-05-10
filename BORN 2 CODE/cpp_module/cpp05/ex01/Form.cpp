#include "Form.hpp"

Form::Form()
	:_name("UNKNOWN"), _signGrade(1), _exeGrade(1), _sign(false)
{
}

Form::Form(const std::string &name, const int &s_grade, const int &e_grade)
	:_name(name), _signGrade(s_grade), _exeGrade(e_grade), _sign(false)
{
	if (_signGrade < GRADE_MAX || _exeGrade < GRADE_MAX)
		throw GradeTooHighException();
	else if (_signGrade > GRADE_MIN || _exeGrade > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form &source)
	:_name(source._name), _signGrade(source._signGrade), _exeGrade(source._exeGrade), _sign(false)
{
}

Form &Form::operator = (const Form &source)
{
	if (this == &source)
		return (*this);
	this->_sign = source.getSign();
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExeGrade() const
{
	return (this->_exeGrade);
}

bool Form::getSign() const
{
	return (this->_sign);
}

void Form::beSigned(const Bureaucrat &someone)
{
	if (someone.getGrade() <= this->_signGrade)
		this->_sign = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form's Grade is Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form's Grade is Too Low!");
}

std::ostream &operator << (std::ostream &out, const Form &source)
{
	out << "Form Name : " << source.getName() << std::endl;
	out << "Sign Grade : " << source.getSignGrade() << std::endl;
	out << "Execute Grade : " << source.getExeGrade() << std::endl;
	out << "Sign Status : " << std::boolalpha << source.getSign() << std::noboolalpha << std::endl;
	return (out);
}
