/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:11:01 by dferreir          #+#    #+#             */
/*   Updated: 2023/09/08 11:57:03 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return(std::cout << "Wrong number of arguments" << std::endl, EXIT_FAILURE);
	Harl harl;

	harl.complain(argv[1]);
}
