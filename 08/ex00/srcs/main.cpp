#include "easyfind.hpp"
#include <vector>
#include <list>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Need two arguments" << std::endl;
		return -1;
	}

	int	needle = std::stoi(argv[1]);
	int	array[5] = {0, 1, 2, 3, 4};
	std::vector<int>	vect(array, array+sizeof(array)/sizeof(int));
	std::list<int>		list(array, array+sizeof(array)/sizeof(int));

	std::cout << "ARRAY:	";
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "NEEDLE:	" << needle << std::endl;

	try {std::cout << "Vector test:	"; easyfind(vect, needle);}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}
	try {std::cout << "List test:	"; easyfind(list, needle);}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}

	return 0;
}
