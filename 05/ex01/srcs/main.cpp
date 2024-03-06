#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("John", 1);
		Form x("[Pig blood for Slayer concert]", 71, 34);
		a.signForm(x);
		std::cout << x;
	}
	catch (Form::GradeTooLowException &x)
	{
		std::cout << x.what() << std::endl;
	}
	try
	{
		Bureaucrat b("James", 150);
		Form y("[Lighshow for Slayer concert]", 71, 34);
		b.signForm(y);
		std::cout << y;
	}
	catch (Form::GradeTooLowException &y)
	{
		std::cout << y.what() << std::endl;
	}
	try
	{
		Bureaucrat c("Janine", 71);
		Form z("[Beer for Slayer concert]", 71, 34);
		c.signForm(z);
		std::cout << z;
	}
	catch (Form::GradeTooLowException &z)
	{
		std::cout << z.what() << std::endl;
	}
	return 0;
}
