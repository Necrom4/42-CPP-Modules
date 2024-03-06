#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << "---Construction---" << std::endl;
		Intern	John;
		Intern	James(John);
		AForm*	shrub_form;
		AForm*	robo_form;
		AForm*	pres_form;
		AForm*	unex_form;
		
		std::cout << "---Form Creation---" << std::endl;

		std::cout << "   [Shrubbery Creation]" << std::endl;
		shrub_form = John.makeForm("shrubbery creation", "Test_form1");
		std::cout << "   [Robotomy Request]" << std::endl;
		robo_form = John.makeForm("robotomy request", "Test_form2");
		std::cout << "   [Presidential Pardon]" << std::endl;
		pres_form = John.makeForm("presidential pardon", "Test_form3");
		std::cout << "   [Unexistant Form (test)]" << std::endl;
		unex_form = John.makeForm("unexistant form", "Test_formX");

		std::cout << "---Deletion---" << std::endl;

		delete shrub_form;
		delete robo_form;
		delete pres_form;
		delete unex_form;
	}
	catch (std::exception &x)
	{
		std::cout << x.what() << std::endl;
	}
	return 0;
}
