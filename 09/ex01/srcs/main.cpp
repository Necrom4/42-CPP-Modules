#include "RPN.hpp"

int main(int argc, char **argv)
{
	float	total;

	if (RPN::errorHandling(argc, argv))
		return -1;
	total = RPN::calcul(std::string(argv[1]));
	if (total == -1)
		return -1;
	std::cout << total << std::endl;

	return 0;
}
