#include "Form.hpp"

Form::Form(std::string name, int signableGrade, int executableGrade): name(name), isSigned(false), signableGrade(signableGrade), executableGrade(executableGrade)
{
	std::cout << "Form " << name << " constructor called" << std::endl;
	if (signableGrade < 1 || executableGrade < 1)
		throw Form::GradeTooHighException();
	if (signableGrade > 150 || executableGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): name(copy.getName() + "_copy"), signableGrade(copy.getSignableGrade()), executableGrade(copy.getExecutableGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	std::cout << "Form " << copy.getName() << " copied into " << name << std::endl;
	*this = copy;
}

Form	&Form::operator=(const Form &copy)
{
	std::cout << "Form assignement operator called" << std::endl;
	isSigned = copy.getIsSigned();
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return name;
}

int			Form::getIsSigned() const
{
	return isSigned;
}

int			Form::getSignableGrade() const
{
	return signableGrade;
}

int			Form::getExecutableGrade() const
{
	return executableGrade;
}

void		Form::beSigned(const Bureaucrat &x)
{
	if (x.getGrade() > signableGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream	&operator<<(std::ostream& x, const Form &src)
{
	x << "Form " << src.getName() << std::endl
	<< "	Signable grade: " << src.getSignableGrade() << std::endl
	<< "	Execution grade: " << src.getExecutableGrade() << std::endl
	<< "	Signed status: " << src.getIsSigned() << std::endl;
	return x;
}
