#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal " << copy.type << " copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	type = copy.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	if (type != "WrongAnimal")
		std::cout << "WrongAnimal " << type << " destructor called" << std::endl;
	else
		std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound()const
{
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string	WrongAnimal::getType()const
{
	return type;
}
