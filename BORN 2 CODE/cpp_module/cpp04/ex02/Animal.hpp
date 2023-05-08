#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &source);
	Animal &operator = (const Animal &source);
	virtual ~Animal();
	virtual void makeSound() const = 0;
};

#endif