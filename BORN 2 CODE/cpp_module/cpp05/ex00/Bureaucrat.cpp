#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name("UNKNOWN"), grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
	:name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
	:name(source.name), grade(source.grade)
{
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &source)
{
	if (this == &source)
		return (*this);
	// static_cast<std::string>(this->name) = source.getName(); // const 성질이 아예 사라짐
	*(const_cast<std::string *>(&this->name)) = source.getName();
	this->grade = source.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGraed()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGraed()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &source)
{
	out << source.getName() << ", bureaucrat grade " << source.getGrade() << std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High exception!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low exception!");
}
