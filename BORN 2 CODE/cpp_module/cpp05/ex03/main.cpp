#include "Intern.hpp"

int main()
{
	Bureaucrat b1("Young", 1);
	Bureaucrat b2("Hyeseo", 15);
	Bureaucrat b3("Junyoung", 70);
	Bureaucrat b4("Siyang", 140);

	Intern intern;
	AForm *f1 = intern.makeForm("presidentialpardon request" ,"Chang Chen");
	AForm *f2 = intern.makeForm("robotomy request","Terminator");
	AForm *f3 = intern.makeForm("shrubberycreation request", "Home");
	AForm *wrong_form = intern.makeForm("Wrong Form", "Don't create form!");

	std::cout << std::endl;
	static_cast<void>(wrong_form);

	std::cout << b1 << b2 << b3 << b4 << std::endl;

	std::cout << std::endl;
	std::cout << *f1 << std::endl << *f2 << std::endl << *f3 << std::endl;
	std::cout << std::endl;
	f1->beSigned(b2);
	f2->beSigned(b3);
	f3->beSigned(b4);
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
