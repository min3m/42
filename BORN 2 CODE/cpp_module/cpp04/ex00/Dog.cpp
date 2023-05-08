#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &source)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	(*this) = source;
}

Dog &Dog::operator = (const Dog &source)
{
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Default Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
