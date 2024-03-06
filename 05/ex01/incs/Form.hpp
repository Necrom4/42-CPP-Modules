#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signableGrade;
		const int			executableGrade;
	public:
		Form();
		Form(const std::string name, int grade, int exec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		std::string	getName() const;
		int			getIsSigned() const;
		int			getSignableGrade() const;
		int			getExecutableGrade() const;

		void		beSigned(const Bureaucrat &x);

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
std::ostream	&operator<<(std::ostream& x, const Form &src);

#endif
