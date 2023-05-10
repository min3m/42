#include "Animal.hpp"

Animal::Animal()
{
	this->type = "???";
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	(*this) = source;
}

Animal &Animal::operator = (const Animal &source)
{
	std::cout << "Animal Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Default Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}
