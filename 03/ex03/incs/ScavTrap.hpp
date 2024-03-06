#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	gg_mode;
	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &src);
		virtual ~ScavTrap();
		void	attack(std::string const &target);
		void	guardGate();
};

#endif
