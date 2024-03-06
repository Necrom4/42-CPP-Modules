#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << type << " constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignement operator called" << std::endl;
	type = copy.getType();
	brain = new Brain(*copy.brain);
	return *this;
}

Cat::~Cat()
{
	std::cout << type << " destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound()const
{
	std::cout << "Meow!" << std::endl;
}
