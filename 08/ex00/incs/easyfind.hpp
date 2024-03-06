#pragma once
#include <iostream>
#include <algorithm>

class notfound: public std::exception
{
	public:
		const char* what() const throw(){return "Needle not found.";}
};

template <typename T>
void easyfind(T &array, int needle)
{
	if (std::find(array.begin(), array.end(), needle) != array.end())
		std::cout << "Needle found in array." << std::endl;
	else
		throw notfound();
}
