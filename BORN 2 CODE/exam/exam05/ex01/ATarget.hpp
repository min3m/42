#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"


class ATarget
{
protected:
	std::string _type;

	ATarget();
	ATarget(const ATarget &src);
	ATarget &operator=(const ATarget &src);

public:
	ATarget(const std::string &tpye);
	virtual ~ATarget();
	const std::string &getType() const;
	virtual ATarget *clone() const = 0;
	void getHitBySpell(const ASpell &spell) const;
};
