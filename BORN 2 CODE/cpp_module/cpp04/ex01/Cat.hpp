#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &source);
	Cat &operator = (const Cat &source);
	virtual ~Cat();
	virtual void makeSound() const;
	std::string get_idea(int index) const;
	void set_idea(const std::string &think, int index);
};

#endif
