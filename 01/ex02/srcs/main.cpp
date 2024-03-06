/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:35:23 by dferreir          #+#    #+#             */
/*   Updated: 2023/07/04 11:49:21 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Original:	" << &string << "	=  " << string << std::endl;
	std::cout << "Pointer:	" << stringPTR << "	=  " << *stringPTR << std::endl;
	std::cout << "Reference:	" << &stringREF << "	=  " << stringREF << std::endl;
	return (0);
}
