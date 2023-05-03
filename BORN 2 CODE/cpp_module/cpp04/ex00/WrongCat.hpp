#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string type;

public:
	WrongCat();
	WrongCat(const WrongCat &source);
	WrongCat &operator = (const WrongCat &source);
	~WrongCat();
	void makeSound() const;
};

#endif
