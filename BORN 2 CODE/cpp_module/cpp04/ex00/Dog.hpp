#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	Dog(const Dog &source);
	Dog &operator = (const Dog &source);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
