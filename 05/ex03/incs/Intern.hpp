#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm*	makeForm(std::string formName, std::string target);
};

#endif
