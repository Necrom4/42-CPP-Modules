#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm* form;
	if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new ShrubberyCreationForm(target);
		return (form);
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new RobotomyRequestForm(target);
		return (form);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates " << formName << std::endl;
		form = new PresidentialPardonForm(target);
		return (form);
	}
	else
	{
		std::cout << "Intern could not create " << formName << std::endl;
		return 0;;
	}
}
