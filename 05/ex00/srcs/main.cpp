#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("John", 1);
		std::cout << a;
		a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &x)
	{
		std::cout << x.what() << std::endl;
	}
	try
	{
		Bureaucrat b("James", 150);
		std::cout << b;
		b.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &x)
	{
		std::cout << x.what() << std::endl;
	}
	return (0);
}
