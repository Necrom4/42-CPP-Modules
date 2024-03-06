#pragma once
#include <iostream>
#include <string>
#include <vector>

class RPN
{
	private:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
	public:
		~RPN();

		static int	errorHandling(int argc, char **argv);
		static float	calcul(std::string expr);
};
