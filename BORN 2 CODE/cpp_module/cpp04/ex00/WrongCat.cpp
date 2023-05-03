#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &source)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	(*this) = source;
}

WrongCat &WrongCat::operator = (const WrongCat &source)
{
	std::cout << "WrongCat Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "???" << std::endl;
}
