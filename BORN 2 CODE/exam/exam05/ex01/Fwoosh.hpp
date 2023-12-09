#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <string>

class Fwoosh : public ASpell
{
public:
	Fwoosh();
	virtual ~Fwoosh();

	virtual ASpell *clone() const;
};
