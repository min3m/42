// #ifndef MATERIASOURCE_HPP
// #define MATERIASOURCE_HPP

// #include "AMateria.hpp"

// class MateriaSource
// {
// public:
// 	virtual ~MateriaSource() {}
// 	virtual void learnMateria(AMateria*);
// 	virtual AMateria* createMateria(std::string const & type);
// };

// #endif
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->skills[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source.skills[i])
			this->skills[i] = source.skills[i]->clone();
		else
			this->skills[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator = (const MateriaSource &source)
{
	std::cout << "MateriaSource Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
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

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Default Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->skills[i])
			delete this->skills[i];
	}
}

void MateriaSource::learnMateria (AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->skills[i])
		{
			this->skills[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria (std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->skills[i]->getType() == type)
			return (this->skills[i]->clone());
	}
	return (NULL);
}
