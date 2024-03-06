/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:00:30 by dferreir          #+#    #+#             */
/*   Updated: 2023/08/28 10:31:37 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	is_word(std::string str, char *arg, int i)
{
	int	j = -1;
	int	n = i;
	while (arg[++j])
		if (arg[j] != str[n++])
			break;
	if (j == (n - i))
		return (n - i);
	return 0;
}

int	main(int argc, char **argv)
{
	int				i = -1;
	int				x = 0;
	char			c;
	std::string		str;
	std::ifstream	infile;
	std::ofstream	outfile;
	if (argc != 4)
	{
		std::cout << "Invalid input, arguments must include: One file, two strings" << std::endl;
		return 1;
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "An error occured while opening " << argv[1] << std::endl;
		return 1;
	}
	while (!infile.eof() && infile >> std::noskipws >> c)
		str = str + c;
	infile.close();
	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "An error occured while opening "
			<< (std::string(argv[1]) + ".replace").c_str() << std::endl;
		return 1;
	}
	while (++i < (int)str.size())
	{
		x = is_word(str, argv[2], i);
		i += x;
		if (x > 0)
		{
			outfile << argv[3];
			i--;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}
