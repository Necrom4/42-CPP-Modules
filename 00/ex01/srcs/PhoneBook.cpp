/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:34:08 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/13 10:09:17 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void	PhoneBook::Start()
{
	std::cout << "     _________________" << std::endl;
	std::cout << " ___/Awesome PhoneBook\\___" << std::endl;
	std::cout << "/_________________________\\" << std::endl;
	std::cout << "|ADD	: Add a contact	  |" << std::endl;
	std::cout << "|SEARCH	: Search a contact|" << std::endl;
	std::cout << "|EXIT	: Close PhoneBook |" << std::endl;
	std::cout << "\\_________________________/" << std::endl;
}

void	PhoneBook::AddContact()
{
	static int	i;
	this->Contacts[i % 8].Init();
//	this->Contacts[i % 8].Index(i);
	i++;
}

std::string	PhoneBook::PrintCase(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void	PhoneBook::PrintContactsList()
{
	int	i = -1;

	if (this->Contacts[0].GetFirstName().empty())
	{
		std::cout << "-Your PhoneBook is empty" << std::endl;
		return;
	}
	while (!this->Contacts[++i].GetFirstName().empty())
	{
		std::cout << "|" << std::setw(10) << i + 1 << std::flush;
		std::cout << "|" << std::setw(10) << PrintCase(this->Contacts[i].GetFirstName()) << std::flush;
		std::cout << "|" << std::setw(10) << PrintCase(this->Contacts[i].GetLastName()) << std::flush;
		std::cout << "|" << std::setw(10) << PrintCase(this->Contacts[i].GetNickName()) << "|" << std::flush;
		std::cout << std::endl;
	}
}

int	PhoneBook::ValidInput(std::string str)
{
	int	i = -1;
	while (str[++i])
		if (!isdigit(str[i]))
			break;
	if (!str[i])
		if (stoi(str) >= 1 && stoi(str) <= 8 && !this->Contacts[stoi(str) - 1].GetFirstName().empty())
			return (0);
	return (1);
}

void	PhoneBook::PrintContactInfo()
{
	if (this->Contacts[0].GetFirstName().empty())
		return;
	std::string	input = "";
	std::string	str = "";
	std::cout << std::endl << ">Display information about #";
	while (!std::cin.eof() && str == "")
		if (std::getline(std::cin, str) && str != "")
			input = str;
	str = "";
	while (this->ValidInput(input))
	{
		std::cout << "-The Contact you chose does not exist" << std::endl
			<< ">Display information about #";
		while (!std::cin.eof() && str == "")
			if (std::getline(std::cin, str) && str != "")
				input = str;
		str = "";
	}
	int	index = stoi(input) - 1;
	this->Contacts[index].Display(index);
}
