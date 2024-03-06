#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), target(copy.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > getExecutableGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file(getName() + "_shrubbery");
    	file << "        . . ." << std::endl
    		 << "      .        .  .     ..    ." << std::endl
    		 << "   .                 .         .  ." << std::endl
    		 << "                   ." << std::endl
    		 << "                  .                .." << std::endl
    		 << "  .          .            .              ." << std::endl
    		 << "  .            '.,        .               ." << std::endl
    		 << "  .              'b      *" << std::endl
    		 << "   .              '$    #.                .." << std::endl
    		 << "  .    .           $:   #:               ." << std::endl
    		 << "..      .  ..      *#  @):        .   . ." << std::endl
    		 << "             .     :@,@):   ,.**:'   ." << std::endl
    		 << " .      .,         :@@*: ..**'      .   ." << std::endl
    		 << "          '#o.    .:(@'.@*    ." << std::endl
    		 << "  .  .       'bq,..:,@@*'   ,*      .  ." << std::endl
    		 << "             ,p$q8,:@)'  .p*'      ." << std::endl
    		 << "      .     '  . '@@Pp@@*'    .  ." << std::endl
    		 << "       .  . ..    Y7'.'     .  ." << std::endl
    		 << "                 :@):." << std::endl
    		 << "                .:@:'." << std::endl
    		 << "              .::(@:." << std::endl;
		file.close();
	}
}
