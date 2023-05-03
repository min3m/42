#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
	:_type("")
{
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
	:_type(type)
{
	std::cout << "AMateria String Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &source)
{
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = source;
}

AMateria &AMateria::operator = (const AMateria &source)
{
	std::cout << "AMateria Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->_type = source.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " use skill!" << std::endl;
}
