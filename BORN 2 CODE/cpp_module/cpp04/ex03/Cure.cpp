#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	:AMateria("cure")
{
	std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure &source)
	:AMateria(source)
{
	std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure &Cure::operator = (const Cure &source)
{
	std::cout << "Cure Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->_type = source._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Default Destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria *tmp = new Cure();

	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
