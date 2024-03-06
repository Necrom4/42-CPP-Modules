/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:01:00 by dferreir          #+#    #+#             */
/*   Updated: 2023/07/05 10:45:20 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_weapon = 0;
}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	if (this->_weapon != 0 && this->_weapon->getType() != "")
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
	{
		std::cout << _name << "doesn't have any weapon equipped" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->_weapon = &_weapon;
}
