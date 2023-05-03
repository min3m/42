#include "Dog.hpp"
#include "Cat.hpp"

# define ARRAY_SIZE 4

int main()
{
	// Animal a; -> 추상 클래스이기 때문에 객체 생성 불가능!
	Animal *c = new Cat();
	Animal *d = new Dog();

	c->makeSound();
	d->makeSound();

	delete d;
	delete c;
}
