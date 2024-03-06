#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hit_pts = 100;
	eng_pts = 100;
	atk_dmg = 30;
	std::cout << "FragTrap " << _name << " was initialized!" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	hit_pts  = 100;
	eng_pts = 100;
	atk_dmg = 30;
	std::cout << "FragTrap " << _name << " was initialized!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap " << copy._name << " duplicator was called!" << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap " << src._name << " was copied with assignment operator!" << std::endl;
	_name = src._name;
	hit_pts = src.hit_pts;
	eng_pts = src.eng_pts;
	atk_dmg = src.atk_dmg;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (eng_pts > 0 && hit_pts > 0)
	{
		std::cout << "FragTrap " << _name << " attacked " << target << ": -" << atk_dmg << std::endl;
	}
	else if (!eng_pts)
		std::cout << "FragTrap " << _name << " is out of energy points!" << std::endl;
	else if (!hit_pts)
		std::cout << "FragTrap " << _name << " is dead and cannot attack!" << std::endl;
	eng_pts--;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "High Five, guys!" << std::endl;
}
