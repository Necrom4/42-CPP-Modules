/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:43:48 by dferreir          #+#    #+#             */
/*   Updated: 2023/05/26 11:02:19 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 1;
	int j = 0;

	if (argc > 1)
	{
		while (argv[i])
		{
			while (argv[i][j])
				std::cout << (char)toupper(argv[i][j++]);
			std::cout << " ";
			j = 0;
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}
