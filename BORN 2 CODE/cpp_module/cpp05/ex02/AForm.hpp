#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	std::string _target;
	const std::string _name;
	const int _signGrade;
	const int _exeGrade;
	bool _signed;

public:
	AForm();
	AForm(const std::string &target, const std::string &name, const int &s_grade, const int &e_grade);
	AForm(const AForm &source);
	AForm &operator = (const AForm &source);
	virtual ~AForm();
	std::string getTarget() const;
	std::string getName() const;
	int getSignGrade() const;
	int getExeGrade() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat &someone);
	virtual void execute(Bureaucrat const & executor) const = 0;
	void executalbe(Bureaucrat const & executor) const;
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
	class DoseNotSingedException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
	class FileOpenException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};
std::ostream &operator << (std::ostream out, const AForm &source);

#endif
