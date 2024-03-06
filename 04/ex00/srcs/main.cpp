#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete	meta;
	delete	i;
	delete	j;

	std::cout << std::endl;

	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	std::cout << w_meta->getType() << " " << std::endl;
	std::cout << w_i->getType() << " " << std::endl;
	w_meta->makeSound();
	w_i->makeSound();

	delete	w_meta;
	delete	w_i;

	return (0);
}
