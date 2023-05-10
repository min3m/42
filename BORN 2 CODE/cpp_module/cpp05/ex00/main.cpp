#include "Bureaucrat.hpp"

int main()
{
	std::cout << "[Case 1]" << std::endl;
	{
		Bureaucrat jim("jim", 3);
		try
		{
			std::cout << jim << std::endl;
			jim.incrementGraed();
			std::cout << jim << std::endl;
			jim.incrementGraed();
			std::cout << jim << std::endl;
			jim.incrementGraed();
			std::cout << jim << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n[Case 2]" << std::endl;
	{
		Bureaucrat john("john", 149);
		try
		{
			std::cout << john << std::endl;
			john.decrementGraed();
			std::cout << john << std::endl;
			john.decrementGraed();
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
			karen.decrementGraed();
			std::cout << karen << std::endl;
			karen.decrementGraed();
			std::cout << karen << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
