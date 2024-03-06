/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:38:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/07/05 10:02:21 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	if (this->_weapon.getType() != "")
		std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
	{
		std::cout << _name << "doesn't have any weapon equipped" << std::endl;
	}
}
