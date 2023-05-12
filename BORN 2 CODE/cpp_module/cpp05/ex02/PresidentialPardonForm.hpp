#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &source);
	PresidentialPardonForm(const PresidentialPardonForm &source);
	PresidentialPardonForm &operator = (const Bureaucrat &source);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
