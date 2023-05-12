#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("UNKNWON", "RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:AForm(target, "RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
	:AForm(source)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	if (this == &source)
		return (*this);
	return (*dynamic_cast<RobotomyRequestForm *>(&AForm::operator=(source)));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	executalbe(executor);
	std::cout << "*    Some driling noises...    *" << std::endl;
	srand((unsigned int)time(NULL));
	int num = rand();

	if (num % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << getTarget() << " failed failed to be robotomized..." << std::endl;
}

