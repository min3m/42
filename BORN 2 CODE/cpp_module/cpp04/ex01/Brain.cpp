#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Defualt Constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "Default idea";
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	(*this) = source;
}

Brain &Brain::operator = (const Brain &source)
{
	std::cout << "Brain Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	for(int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Default Destructor called" << std::endl;
}

std::string Brain::get_idea(int index) const
{
	return (ideas[index]);
}

void Brain::set_idea(const std::string &think, int index)
{
	this->ideas[index] = think;
}
