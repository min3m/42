#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &source);
	WrongAnimal &operator = (const WrongAnimal &source);
	~WrongAnimal();
	void makeSound() const;
};

#endif
