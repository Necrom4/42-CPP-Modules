/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:34:07 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/14 15:52:54 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	int	i = -1;

	Zombie *zombien = new Zombie[N];
	while (++i < N)
		zombien[i].nameZ(name);
	return (zombien);
}
