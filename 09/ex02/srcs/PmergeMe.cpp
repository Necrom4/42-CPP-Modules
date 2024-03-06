#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy){*this = copy;}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){(void)copy; return *this;}

PmergeMe::~PmergeMe(){}

int		PmergeMe::errorHandling(int argc, char **argv)
{
	if (argc < 2)
	{	std::cerr << "Error: no arguments" << std::endl; return 1;}
	for (int i = 1; i < argc; i++)
		for (size_t j = 0; argv[i][j]; j++)
		{
			if (!std::isdigit(argv[i][j]))
			{
				if (argv[i][j] == '-')
					std::cerr << "Error: negative number\n[" << argv[i] << "]" << std::endl;
				else
					std::cerr << "Error: wrong format\n[" << argv[i] << "]" << std::endl;
				return 1;
			}
			else if (std::stod(argv[i]) > 2147483647)
			{	std::cerr << "Error: out of range\n[" << argv[i] << "]" << std::endl; return 1;}
		}

	return 0;
}
