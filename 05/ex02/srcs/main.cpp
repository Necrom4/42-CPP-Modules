#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		std::cout << "---Construction---" << std::endl;
        Bureaucrat a("John", 2);
		Bureaucrat b(a);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

		std::cout << "---Execution---" << std::endl;
		std::cout << "   [Shrubbery Creation]" << std::endl;
        a.signForm(form1);
        a.executeForm(form1);
		std::cout << "   [Robotomy Request]" << std::endl;
        a.signForm(form2);
        a.executeForm(form2);
        a.executeForm(form2);
        a.executeForm(form2);
		std::cout << "   [Presidential Pardon]" << std::endl;
        a.signForm(form3);
        a.executeForm(form3);
		std::cout << "---Deletion---" << std::endl;
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	return 0;
}
