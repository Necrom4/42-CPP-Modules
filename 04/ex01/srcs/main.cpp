#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Dog basic;
	Dog tmp = basic;
	std::cout << std::endl;
	const Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	return 0;
}
