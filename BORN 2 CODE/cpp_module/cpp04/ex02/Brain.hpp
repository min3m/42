#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &source);
	Brain &operator = (const Brain &source);
	~Brain();
	std::string get_idea(int index) const;
	void set_idea(const std::string &think, int index);
};


#endif
