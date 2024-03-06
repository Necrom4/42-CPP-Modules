#ifndef FRAPTRAP_HPP
#define FRAPTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &src);
		virtual ~FragTrap();
		void	attack(std::string const &target);
		void	highFiveGuys(void);
};

#endif
