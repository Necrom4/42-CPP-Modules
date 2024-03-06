#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignement operator called" << std::endl;
	type = copy.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << type << " destructor called" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "Woaf!" << std::endl;
}
