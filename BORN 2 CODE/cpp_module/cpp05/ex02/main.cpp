#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b1("Young", 1);
	Bureaucrat b2("Hyeseo", 15);
	Bureaucrat b3("Junyoung", 70);
	Bureaucrat b4("Siyang", 140);

	AForm *f1 = new PresidentialPardonForm("Chang Chen");
	AForm *f2 = new RobotomyRequestForm("Terminator");
	AForm *f3 = new ShrubberyCreationForm("Home");

	std::cout << b1 << b2 << b3 << b4 << std::endl;

	std::cout << std::endl;
	std::cout << *f1 << std::endl << *f2 << std::endl << *f3 << std::endl;
	std::cout << std::endl;
	b2.signForm(*f1);
	b3.signForm(*f2);
	b4.signForm(*f3);
	std::cout << std::endl;
	b2.executeForm(*f1);
	b3.executeForm(*f2);
	b4.executeForm(*f3);
	std::cout << std::endl;
	b1.executeForm(*f1);
	std::cout << std::endl;
	b1.executeForm(*f2);
	std::cout << std::endl;
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;

	return (0);
}
