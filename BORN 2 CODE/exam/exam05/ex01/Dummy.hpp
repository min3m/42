#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy();
	virtual ~Dummy();

	virtual ATarget *clone() const;
};
