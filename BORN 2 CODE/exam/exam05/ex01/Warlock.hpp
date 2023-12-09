#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "Dummy.hpp"
#include "Fwoosh.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell *> _SpellBook;
	typedef std::map<std::string, ASpell *>::iterator Iter;

	Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &src);
	void introduce() const;
	void learnSpell(const ASpell *spell);
	void forgetSpell(const std::string spell);
	void launchSpell(const std::string spellname, ATarget &target);
};

