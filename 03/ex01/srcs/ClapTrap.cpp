#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), hit_pts(10), eng_pts(10), atk_dmg(0)
{
	std::cout << "ClapTrap " << _name << " was initialized!" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : _name(_name), hit_pts(10), eng_pts(10), atk_dmg(0)
{
	std::cout << "ClapTrap " << _name << " was initialized!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap " << copy._name << " duplicator was called!" << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap " << src._name << " was copied with assignment operator!" << std::endl;
	_name = src._name;
	hit_pts = src.hit_pts;
	eng_pts = src.eng_pts;
	atk_dmg = src.atk_dmg;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (eng_pts > 0 && hit_pts > 0)
	{
		std::cout << "ClapTrap " << _name << " attacked " << target << ": -" << atk_dmg << std::endl;
	}
	else if (!eng_pts)
		std::cout << "ClapTrap " << _name << " is out of energy points!" << std::endl;
	else if (!hit_pts)
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
	eng_pts--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hit_pts)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	else if (!(hit_pts - amount))
	{
		std::cout << "ClapTrap " << _name << " was attacked and is now dead!" << std::endl;
		hit_pts -= amount;
		return;
	}
	std::cout << "ClapTrap " << _name << " was attacked and lost " << amount << " health points!" << std::endl;
	hit_pts -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int offset = 0;
	if (eng_pts > 0 && hit_pts > 0)
	{
		if (hit_pts + amount > 10)
			offset = hit_pts + amount - 10;
		std::cout << "ClapTrap " << _name << " repaired " << amount << " health points!" << std::endl;
		eng_pts--;
		hit_pts += amount - offset;
	}
	else if (eng_pts == 0)
		std::cout << "ClapTrap " << _name << " is out of energy points, hence cannot be repaired!" << std::endl;
	else if (hit_pts == 0)
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
}
