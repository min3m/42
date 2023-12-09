#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::Warlock(std::string name, std::string title)
	:_name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &)
{
}

Warlock &Warlock::operator=(const Warlock &)
{
	return *this;
}

Warlock::~Warlock() { std::cout << _name << ": My job here is done!" << std::endl; }
const std::string &Warlock::getName() const { return (_name); }
const std::string &Warlock::getTitle() const { return (_title); }
void Warlock::setTitle(const std::string &src) { _title = src; }
void Warlock::introduce() const { std::cout << _name << ": I am "<< _name << ", " << _title << "!" << std::endl; }

void Warlock::learnSpell(const ASpell *spell)
{
	Iter it = _SpellBook.find(spell->getName());

	if (it == _SpellBook.end())
		_SpellBook.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(const std::string spell)
{
	Iter it = _SpellBook.find(spell);

	if (it != _SpellBook.end())
	{
		delete it->second;
		_SpellBook.erase(it);
	}
}

void Warlock::launchSpell(const std::string spellname, ATarget &target)
{
	Iter it = _SpellBook.find(spellname);

	if (it != _SpellBook.end())
		it->second->launch(target);
}
