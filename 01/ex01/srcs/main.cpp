/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:07:35 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/14 15:48:54 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main()
{
	std::string name;
	std::string n_tmp;
	int	N;
	int	i = -1;

	std::cout << "Name your new pet Zombies: " << std::flush;
	std::cin >> name;
	std::cout << "How many pet Zombies do you wish to spawn: " << std::flush;
	std::cin >> n_tmp;
	N = stoi(n_tmp);
	Zombie *zombien = zombieHorde(N, name);
	while (++i < N)
		zombien[i].announce();
	delete[] zombien;
	return (0);
}
