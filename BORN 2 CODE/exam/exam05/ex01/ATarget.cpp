#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(const ATarget &)
{
}

ATarget &ATarget::operator=(const ATarget &)
{ return (*this); }

ATarget::ATarget(const std::string &tpye)
	:_type(tpye)
{
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType() const
{ return (_type); }

void ATarget::getHitBySpell(const ASpell &spell) const
{ std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl; }
