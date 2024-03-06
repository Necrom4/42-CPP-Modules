#include "AForm.hpp"

AForm::AForm(std::string name, int signableGrade, int executableGrade): name(name), isSigned(false), signableGrade(signableGrade), executableGrade(executableGrade)
{
	std::cout << "AForm " << name << " constructor called" << std::endl;
	if (signableGrade < 1 || executableGrade < 1)
		throw AForm::GradeTooHighException();
	if (signableGrade > 150 || executableGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): name(copy.getName() + "_copy"), signableGrade(copy.getSignableGrade()), executableGrade(copy.getExecutableGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;
	std::cout << "AForm " << copy.getName() << " copied into " << name << std::endl;
	*this = copy;
}

AForm	&AForm::operator=(const AForm &copy)
{
	std::cout << "AForm assignement operator called" << std::endl;
	isSigned = copy.getIsSigned();
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << name << " destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return name;
}

int			AForm::getIsSigned() const
{
	return isSigned;
}

int			AForm::getSignableGrade() const
{
	return signableGrade;
}

int			AForm::getExecutableGrade() const
{
	return executableGrade;
}

void		AForm::beSigned(const Bureaucrat &x)
{
	if (x.getGrade() > signableGrade)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

std::ostream	&operator<<(std::ostream& x, const AForm &src)
{
	x << "AForm [" << src.getName() << "]" << std::endl
	<< "	Signable status: " << src.getSignableGrade() << std::endl
	<< "	Signed status: " << src.getIsSigned() << std::endl
	<< "	Execution status: " << src.getExecutableGrade() << std::endl;
	return x;
}
