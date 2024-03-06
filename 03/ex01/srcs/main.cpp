#include "ScavTrap.hpp"
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
	std::cout << "\n|ScavTest|\n" << std::endl;
	ScavTrap etrap;
	ScavTrap ftrap("Marcus");
	ScavTrap gtrap(ftrap);
	etrap.attack("Android-X");
	ftrap.takeDamage(10);
	ftrap.takeDamage(10);
	etrap.beRepaired(5);
	etrap.attack("Android-Y");
	ftrap.beRepaired(3);
	gtrap.beRepaired(3);
	ftrap.attack("Android-Z");
	ftrap.beRepaired(3);
	gtrap.guardGate();
	gtrap.guardGate();
	return (0);
}
