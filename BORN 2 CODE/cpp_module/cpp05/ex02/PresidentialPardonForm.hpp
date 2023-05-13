#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &source);
	PresidentialPardonForm(const PresidentialPardonForm &source);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &source);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
