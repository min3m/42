#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("UNKNOWN", "PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:AForm(target, "PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source)
	:AForm(source)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &source)
{
	if (this == &source)
		return (*this);
	return (*dynamic_cast<PresidentialPardonForm *>(&AForm::operator=(source)));
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	executalbe(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
