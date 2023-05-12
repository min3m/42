#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	:name("UNKNOWN"), grade(GRADE_MAX)
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
	:name(name), grade(grade)
{
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	else if (grade > GRADE_MIN)
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

void Bureaucrat::incrementGrade()
{
	if (grade <= GRADE_MAX)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= GRADE_MIN)
		throw GradeTooLowException();
	grade++;
}
void Bureaucrat::signForm(const Form &form) const
{
	if (form.getSign())
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
	{
		std::cout << this->name << " couldn't signed " << form.getName() << " because ";
		throw GradeTooLowException();
	}
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &source)
{
	out << source.getName() << ", bureaucrat grade " << source.getGrade() << std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's Grade is Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's Grade is Too Low!");
}
