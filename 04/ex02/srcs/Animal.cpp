#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << type << " constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal " << type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal " << copy.type << " copy constructor called" << std::endl;
	*this = copy;
}

Animal	&Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignement operator called" << std::endl;
	type = copy.type;
	return *this;
}

Animal::~Animal()
{
	if (type != "Animal")
		std::cout << "Animal " << type << " destructor called" << std::endl;
	else
		std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound()const
{
	std::cout << "Animal makeSound called" << std::endl;
}

std::string	Animal::getType()const
{
	return type;
}
