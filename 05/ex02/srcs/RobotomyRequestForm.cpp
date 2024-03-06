#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), target(copy.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecutableGrade())
		throw AForm::GradeTooLowException();
	std::cout << "DRIIIIILLLLL..." << std::endl;
	int randomValue = (std::rand() % (100 - 0 + 1));
	if (randomValue >= 50)
		std::cout << executor.getName() << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomization of " <<executor.getName() << " failed." << std::endl;
}
