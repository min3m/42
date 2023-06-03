#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error: bad argument" << std::endl;
		std::exit(1);
	}
	try
	{
		PmergeMe pmerge;
		pmerge.init(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
