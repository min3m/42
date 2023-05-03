#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &source)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
}

Dog &Dog::operator = (const Dog &source)
{
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	delete this->_brain;
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Default Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

std::string Dog::get_idea(int index) const
{
	return (this->_brain->get_idea(index));
}

void Dog::set_idea(const std::string &think, int index)
{
	this->_brain->set_idea(think, index);
}
