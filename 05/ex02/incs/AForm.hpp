#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signableGrade;
		const int			executableGrade;
	public:
		AForm();
		AForm(const std::string name, int signableGrade, int executableGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual	~AForm();

		std::string	getName() const;
		int			getIsSigned() const;
		int			getSignableGrade() const;
		int			getExecutableGrade() const;

		void				beSigned(const Bureaucrat &x);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
		class	IsNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Couldn\'t sign";
				}
		};
};
std::ostream	&operator<<(std::ostream& x, const AForm &src);

#endif
