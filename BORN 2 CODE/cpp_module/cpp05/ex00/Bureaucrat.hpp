#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &source);
	~Bureaucrat();
	Bureaucrat &operator = (const Bureaucrat &source);
	std::string getName() const;
	int getGrade() const;
	void incrementGraed();
	void decrementGraed();
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
std::ostream& operator << (std::ostream &out, const Bureaucrat &source);

#endif
