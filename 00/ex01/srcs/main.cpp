/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:07:35 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/01 13:40:21 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	pb;
	std::string	input = "";
	std::string str = "";
	pb.Start();
	while (input.compare("EXIT"))
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (!input.compare("ADD"))
			pb.AddContact();
		else if (!input.compare("SEARCH"))
		{
			pb.PrintContactsList();
			pb.PrintContactInfo();
		}
		else if (input.compare(""))
			std::cout << "Invalid input" << std::endl;
		std::cout << "> ";
		while (!std::cin.eof() && str == "")
			if (std::getline(std::cin, str) && str != "")
				input = str;
		str = "";
	}
	return (0);
}
