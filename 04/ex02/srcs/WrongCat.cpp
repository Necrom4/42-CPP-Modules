#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << type << " constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignement operator called" << std::endl;
	type = copy.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << type << " destructor called" << std::endl;
}

void	WrongCat::makeSound()const
{
	std::cout << "WrongMeow!" << std::endl;
}
