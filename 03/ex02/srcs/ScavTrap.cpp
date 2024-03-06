#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hit_pts = 100;
	eng_pts = 50;
	atk_dmg = 20;
	gg_mode = false;
	std::cout << "ScavTrap " << _name << " was initialized!" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	hit_pts = 100;
	eng_pts = 50;
	atk_dmg = 20;
	gg_mode = false;
	std::cout << "ScavTrap " << _name << " was initialized!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap " << copy._name << " duplicator was called!" << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap " << src._name << " was copied with assignment operator!" << std::endl;
	_name = src._name;
	hit_pts = src.hit_pts;
	eng_pts = src.eng_pts;
	atk_dmg = src.atk_dmg;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (eng_pts > 0 && hit_pts > 0)
	{
		std::cout << "ScavTrap " << _name << " attacked " << target << ": -" << atk_dmg << std::endl;
	}
	else if (!eng_pts)
		std::cout << "ScavTrap " << _name << " is out of energy points!" << std::endl;
	else if (!hit_pts)
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
	eng_pts--;
}

void	ScavTrap::guardGate()
{
	if (this->gg_mode == false)
	{
		this->gg_mode = true;
		std::cout << "ScavTrap " << _name << " is now guarding The Gate!" << std::endl;
	}
	else
	{
		this->gg_mode = false;
		std::cout << "ScavTrap " << _name << " stopped guarding The Gate!" << std::endl;
	}
}
