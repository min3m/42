#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &source)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
}

Cat &Cat::operator = (const Cat &source)
{
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	delete this->_brain;
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Default Destructor called" << std::endl;
	delete (this->_brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::get_idea(int index) const
{
	return (this->_brain->get_idea(index));
}

void Cat::set_idea(const std::string &think, int index)
{
	this->_brain->set_idea(think, index);
}
