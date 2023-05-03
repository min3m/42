#include "Dog.hpp"
#include "Cat.hpp"

# define ARRAY_SIZE 4

int main()
{
	std::cout << "\e[94m*** Test1 ***\e[0m\n";
	{
		Animal *animal_array[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE / 2; i++)
			animal_array[i] = new Dog();
		for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
			animal_array[i] = new Cat();
		for (int i = 0; i < ARRAY_SIZE; i++)
			delete animal_array[i];
	}
	{
		std::cout << "\n\e[96m*** TEST 2 \e[0m\n";
		Dog a1;
		a1.set_idea("Dog think One", 0);
		a1.set_idea("Dog think Two", 1);
		Dog a2;
		a2 = a1;
		a2.set_idea("Copy Dog think Another one", 0);
		std::cout << "\e[95mDog one's first idea is \"" << a1.get_idea(0) << "\" \nCopy Dog's first idea is \"" << a2.get_idea(0) << "\"\e[0m\n";
		std::cout << "\e[95mDog's second idea is \"" << a1.get_idea(1) << "\" \nCopy Dog's second idea is \"" << a2.get_idea(1) << "\"\e[0m\n";

		Cat c1;
		c1.set_idea("Cat think oneone", 0);
		c1.set_idea("Cat think twotwo", 1);
		Cat c2;
		c2.set_idea("Copy Cat think tmp one", 0);
		c2.set_idea("Copy Cat think tmp two", 1);
		c2 = c1;
		std::cout << "\e[95mCat's first idea is \"" << c1.get_idea(0) << "\"\nCopy Cat's first idea is \"" << c2.get_idea(0) << "\"\e[0m\n";
		std::cout << "\e[95mCat's second idea is \"" << c1.get_idea(1) << "\"\nCopy Cat's second idea is \"" << c2.get_idea(1) << "\"\e[0m\n";
	}
	{
		std::cout << "\n\e[96m*** TEST 3***\e[0m\n";

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	system("leaks Animal > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
}
