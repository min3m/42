#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(const Dog &source);
	Dog &operator = (const Dog &source);
	virtual ~Dog();
	virtual void makeSound() const;
	std::string get_idea(int index) const;
	void set_idea(const std::string &think, int index);
};

#endif
