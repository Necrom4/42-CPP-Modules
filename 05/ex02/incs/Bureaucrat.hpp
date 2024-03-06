#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string		name;
		int						grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void		signForm(AForm &x);
		void		executeForm(AForm &x);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too high";
				}
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too low";
				}
		};

};
std::ostream	&operator<<(std::ostream& x, const Bureaucrat &src);

#endif
