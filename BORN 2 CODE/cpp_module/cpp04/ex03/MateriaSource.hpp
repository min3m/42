#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *skills[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &source);
	MateriaSource &operator = (const MateriaSource &source);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
