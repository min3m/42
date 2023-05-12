#include "AForm.hpp"

AForm::AForm()
	:_target("UNKNWON"), _name("UNKNOWN"), _signGrade(1), _exeGrade(1), _signed(false)
{
}

AForm::AForm(const std::string &target, const std::string &name, const int &s_grade, const int &e_grade)
	:_target(target), _name(name), _signGrade(s_grade), _exeGrade(e_grade), _signed(false)
{
	if (_signGrade < GRADE_MAX || _exeGrade < GRADE_MAX)
		throw GradeTooHighException();
	else if (_signGrade > GRADE_MIN || _exeGrade > GRADE_MIN)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &source)
	:_target(source._target), _name(source._name), _signGrade(source._signGrade), _exeGrade(source._exeGrade), _signed(false)
{
}

AForm &AForm::operator = (const AForm &source)
{
	if (this == &source)
		return (*this);
	this->_target = source.getTarget();
	*const_cast<std::string *>(&_name) = source.getName();
	*const_cast<int *>(&_signGrade) = source.getSignGrade();
	*const_cast<int *>(&_exeGrade) = source.getExeGrade();
	this->_signed = source.getSigned();
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getTarget() const
{
	return (this->_target);
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExeGrade() const
{
	return (this->_exeGrade);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::beSigned(const Bureaucrat &someone)
{
	if (someone.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::executalbe(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw DoseNotSingedException();
	if (executor.getGrade() > getExeGrade())
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form's Grade is Too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form's Grade is Too Low!");
}

const char *AForm::DoseNotSingedException::what() const throw()
{
	return ("Form is not Signed!");
}

const char *AForm::FileOpenException::what() const throw()
{
	return ("File open error occurred!");
}

std::ostream &operator << (std::ostream &out, const AForm &source)
{
	out << "AForm Name : " << source.getName() << std::endl;
	out << "Sign Grade : " << source.getSignGrade() << std::endl;
	out << "Execute Grade : " << source.getExeGrade() << std::endl;
	out << "Sign Status : " << std::boolalpha << source.getSigned() << std::noboolalpha << std::endl;
	return (out);
}
