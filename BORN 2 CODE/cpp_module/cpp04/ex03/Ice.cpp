#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
	:AMateria("ice")
{
	std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(const Ice &source)
	:AMateria(source)
{
	std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice &Ice::operator = (const Ice &source)
{
	std::cout << "Ice Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->_type = source._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Default Destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *tmp = new Ice();

	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
