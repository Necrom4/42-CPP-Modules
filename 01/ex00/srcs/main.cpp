/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:07:35 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/14 14:36:17 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main()
{
	std::string name;

	std::cout << "Name your new pet Zombie: " << std::flush;
	std::cin >> name;
	Zombie zombie1(name);
	zombie1.announce();
	std::cout << "Name your new pet Zombie: " << std::flush;
	std::cin >> name;
	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	delete zombie2;
	std::cout << "Name your new pet Zombie: " << std::flush;
	std::cin >> name;
	randomChump(name);
	return (0);
}
