#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	(*this) = source;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &source)
{
	std::cout << "WrongAnimal Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "???" << std::endl;
}
