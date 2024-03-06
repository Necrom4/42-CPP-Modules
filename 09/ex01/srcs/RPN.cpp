#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &copy){*this = copy;}

RPN &RPN::operator=(const RPN &copy){(void)copy; return *this;}

RPN::~RPN(){}

int		RPN::errorHandling(int argc, char **argv)
{
	if (argc != 2)
	{	std::cerr << "Error: wrong number of arguments" << std::endl; return 1;}
	for (size_t i = 0; argv[1][i]; i++)
	{
		if (!std::isdigit(argv[1][i]) && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != '/' && argv[1][i] != ' ')
		{	std::cerr << "Error: wrong format" << std::endl; return 1;}
	}

	std::vector<char>	curr;
	for (size_t i = 0; argv[1][i]; i++)
		if (argv[1][i] != ' ')
			curr.push_back(argv[1][i]);
	if (curr.empty())
	{	std::cerr << "Error: empty" << std::endl; return 1;}
	if (!(std::isdigit(curr[0]) && std::isdigit(curr[1]) && !std::isdigit(curr[curr.size() - 1])))
	{	std::cerr << "Error: wrong format" << std::endl; return 1;}

	return 0;
}

float	RPN::calcul(std::string expr)
{
	int	i = -1;
	while (expr[++i] == ' ');
	float total = std::stof(expr.substr(i, 1));
	std::vector<float>	nums;

	while (expr[++i])
	{
		if (std::isdigit(expr[i]))
			nums.push_back(std::stof(expr.substr(i, 1)));
		else if (expr[i] == ' ');
		else
		{
			int	x = nums.size() - 1;
			float	sub_total = nums[x];
			while (x > 0)
			{
				if (expr[i] == '+')
					sub_total = nums[x - 1] + sub_total;
				else if (expr[i] == '-')
					sub_total = nums[x - 1] - sub_total;
				else if (expr[i] == '*')
					sub_total = nums[x - 1] * sub_total;
				else if (expr[i] == '/')
					sub_total = nums[x - 1] / sub_total;
				if (expr[i] != ' ')
					x--;
				i++;
			}
			while (expr[i] == ' ')
				i++;
			if (!expr[i] || std::isdigit(expr[i]))
			{	std::cerr << "Error: wrong format" << std::endl; return -1;}
			if (expr[i] == '+')
				total += sub_total;
			else if (expr[i] == '-')
				total -= sub_total;
			else if (expr[i] == '*')
				total *= sub_total;
			else if (expr[i] == '/')
				total /= sub_total;
			nums.clear();
			int j = i;
			while (expr[++j] == ' ');
			if (expr[j] && !std::isdigit(expr[j]))
			{	std::cerr << "Error: wrong format" << std::endl; return -1;}
		}
	}
	return total;
}
