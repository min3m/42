#include "Character.hpp"

Character::Character()
	:_name("Unknown")
{
	std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->skills[i] = NULL;
}

Character::Character(const std::string &name)
	:_name(name)
{
	std::cout << "Character String Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->skills[i] = NULL;
}

Character::Character(const Character &source)
	:_name(source._name)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source.skills[i])
			this->skills[i] = source.skills[i]->clone();
		else
			this->skills[i] = NULL;
	}
}

Character &Character::operator = (const Character &source)
{
	std::cout << "Character Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->_name = source._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->skills[i])
			delete this->skills[i];
		if (source.skills[i])
			this->skills[i] = source.skills[i]->clone();
		else
			this->skills[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character Default Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->skills[i])
			delete this->skills[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->skills[i])
		{
			std::cout << this->_name << " equips " << m->getType() << " skill!" << std::endl;
			this->skills[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->skills[idx])
	{
		std::cout << this->_name << " unequips " << this->skills[idx]->getType() << " skill!" << std::endl;
		this->skills[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->skills[idx])
		this->skills[idx]->use(target);
}
