#include "Bureaucrat.hpp"

int main()
{
	std::cout << "[Case 1]" << std::endl;
	{
		try
		{
			Bureaucrat jim("jim", 3);
			std::cout << jim << std::endl;
			jim.incrementGrade();
			std::cout << jim << std::endl;
			jim.incrementGrade();
			std::cout << jim << std::endl;
			jim.incrementGrade();
			std::cout << jim << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n[Case 2]" << std::endl;
	{
		try
		{
			Bureaucrat john("john", 149);
			std::cout << john << std::endl;
			john.decrementGrade();
			std::cout << john << std::endl;
			john.decrementGrade();
			std::cout << john << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n[Case 3]" << std::endl;
	{
		try
		{
			Bureaucrat karen("karen", 151);
			std::cout << karen << std::endl;
			karen.decrementGrade();
			std::cout << karen << std::endl;
			karen.decrementGrade();
			std::cout << karen << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
