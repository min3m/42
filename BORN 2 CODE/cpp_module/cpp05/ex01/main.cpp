#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form topSecret("CIA TopSecret", 3, 3);
	std::cout << topSecret << std::endl;
	std::cout << std::endl;
	{
		Bureaucrat jack("Jack", 45);
		try
		{
			topSecret.beSigned(jack);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		jack.signForm(topSecret);
	}
	{
		std::cout << "\n";
		Bureaucrat joe("Mr.President", 1);
		try
		{
			topSecret.beSigned(joe);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		joe.signForm(topSecret);
	}
	std::cout << "\n";
	{
		try
		{
			Form topSecret("CIA TopSecret", 0, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form topSecret("Korea TopSecret", 151, 12);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
