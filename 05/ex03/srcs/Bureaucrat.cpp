#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	std::cout << name << ", bureaucrat of grade " << grade << " constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	std::cout << "Bureaucrat " << copy.getName() << " copied into " << name << std::endl;
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;
	this->grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int			Bureaucrat::getGrade() const
{
	return grade;
}

void		Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void		Bureaucrat::signForm(AForm &x)
{
	try
	{
		x.beSigned(*this);
		std::cout << *this << " signed " << x.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &y)
	{
		std::cout << *this << " couldn\'t sign " << x.getName() << " because " << y.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm &x)
{
	try
	{
		x.execute(*this);
		std::cout << *this << " executed " << x.getName() << std::endl;
	}
	catch (std::exception &y)
	{
		std::cout << *this << " couldn\'t execute " << x.getName() << " because " << y.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream& x, const Bureaucrat &src)
{
	x << src.getName() << ", bureaucrat grade " << src.getGrade();
	return x;
}
