#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
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
	std::cout << "\n|FragTest|\n" << std::endl;
	FragTrap htrap;
	FragTrap itrap("Marcus");
	FragTrap jtrap(itrap);
	htrap.attack("Android-X");
	htrap.highFiveGuys();
	itrap.takeDamage(10);
	itrap.takeDamage(10);
	htrap.beRepaired(5);
	htrap.attack("Android-Y");
	itrap.beRepaired(3);
	jtrap.beRepaired(3);
	itrap.attack("Android-Z");
	itrap.beRepaired(3);
	htrap.highFiveGuys();
	return 0;
}
