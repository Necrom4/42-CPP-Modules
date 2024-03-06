#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n|CrapTest|\n" << std::endl;
	ClapTrap atrap;
	ClapTrap btrap("Marcus");
	ClapTrap ctrap(btrap);
	atrap.attack("Android-X");
	atrap.takeDamage(10);
	atrap.takeDamage(10);
	btrap.takeDamage(5);
	atrap.beRepaired(5);
	atrap.attack("Android-Y");
	btrap.beRepaired(3);
	ctrap.beRepaired(3);
	btrap.attack("Android-Z");
	btrap.beRepaired(3);
	return (0);
}
