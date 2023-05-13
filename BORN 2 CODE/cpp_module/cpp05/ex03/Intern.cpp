#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &source)
{
	*this = source;
}

Intern &Intern::operator = (const Intern &source)
{
	static_cast<void>(source);
	return (*this);
}

Intern::~Intern()
{
}

const char *Intern::DoseNotExistFormExecption::what() const throw()
{
	return("Intern can't create Form because that Form is not exist!");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string str[3];

	str[0] = "robotomy request";
	str[1] = "presidentialpardon request";
	str[2] = "shrubberycreation request";

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (name == str[i])
			{
				std::cout << "Intern creates " << name << std::endl;
				switch (i)
				{
				case 0:
					return (new RobotomyRequestForm(target));
				case 1:
					return (new PresidentialPardonForm(target));
				case 2:
					return (new ShrubberyCreationForm(target));
				}
			}
		}
		throw DoseNotExistFormExecption();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}
