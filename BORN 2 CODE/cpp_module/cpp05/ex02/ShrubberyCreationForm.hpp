#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &source);
	ShrubberyCreationForm(const ShrubberyCreationForm& source);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm& source);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
