#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &source);
	Intern &operator = (const Intern &source);
	~Intern();
	AForm *makeForm(const std::string &name, const std::string &target);
	class DoseNotExistFormExecption : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
