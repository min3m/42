#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &source)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	(*this) = source;
}

Cat &Cat::operator = (const Cat &source)
{
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Default Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
