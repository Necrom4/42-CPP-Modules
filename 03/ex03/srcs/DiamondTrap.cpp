#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Defalut_clap_trap")
{
	_name = "Default";
	hit_pts = FragTrap::hit_pts;
	eng_pts = ScavTrap::eng_pts;
	atk_dmg = FragTrap::atk_dmg;
	std::cout << "DiamondTrap " << _name << " was initialized!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	_name = name;
	hit_pts = FragTrap::hit_pts;
	eng_pts = ScavTrap::eng_pts;
	atk_dmg = FragTrap::atk_dmg;
	std::cout << "DiamondTrap " << _name << " was initialized!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap " << copy._name << " duplicator was called!" << std::endl;
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << src._name << " was copied with assignment operator!" << std::endl;
	_name = src._name + "_clap_trap";
	hit_pts = src.hit_pts;
	eng_pts = src.eng_pts;
	atk_dmg = src.atk_dmg;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << " ClapTrap name: " << ClapTrap::_name << std::endl;
}
