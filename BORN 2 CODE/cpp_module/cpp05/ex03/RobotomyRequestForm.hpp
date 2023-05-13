#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &source);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &source);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
