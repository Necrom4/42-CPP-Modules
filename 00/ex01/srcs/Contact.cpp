/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:50:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/13 10:09:38 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::GetFirstName()
{
	return (this->FirstName);
}

std::string Contact::GetLastName()
{
	return (this->LastName);
}

std::string Contact::GetNickName()
{
	return (this->NickName);
}

std::string Contact::GetPhoneNumber()
{
	return (this->PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
	return (this->DarkestSecret);
}

void	Contact::Init()
{
	int	i;
	int	num = 0;
	std::string str = "";

	std::cout << "Please enter your contact's first name: ";
	while (!std::cin.eof() && str == "")
		if (std::getline(std::cin, str) && str != "")
			this->FirstName = str;
	str = "";
	std::cout << "Please enter " << this->FirstName << "'s last name: ";
	while (!std::cin.eof() && str == "")
		if (std::getline(std::cin, str) && str != "")
			this->LastName = str;
	str = "";
	std::cout << "Please enter " << this->FirstName << "'s nickname: ";
	while (!std::cin.eof() && str == "")
		if (std::getline(std::cin, str) && str != "")
			this->NickName = str;
	str = "";
	while (!std::cin.eof() && str == "" && num == 0)
	{
		std::cout << "Please enter " << this->FirstName << "'s phone number: ";
		i = -1;
		if (std::getline(std::cin, str) && str != "")
		{
			while (str[++i] && (isdigit(str[i]) || str[i] == ' ' || str[i] == '+'));
			if (!str[i])
			{
				this->PhoneNumber = str;
				num = 1;
			}
			else
				std::cout << "Invalid input" << std::endl;
		}
		str = "";
	}
	std::cout << "Please enter " << this->FirstName << "'s darkest secret: ";
	while (!std::cin.eof() && str == "")
		if (std::getline(std::cin, str) && str != "")
			this->DarkestSecret = str;
	str = "";
	std::cout << "Successfully added " << this->FirstName << " to your PhoneBook"
		<< std::endl;
}

void	Contact::Display(int index)
{
	if (this->FirstName.empty() || this->LastName.empty() || this->NickName.empty()
			|| this->PhoneNumber.empty() || this->DarkestSecret.empty())
		return ;
	std::cout << "	      __________" << std::endl;
	std::cout << " ____________/Contact #" << index << "\\____________" << std::endl;
	std::cout << "/____________________________________\\" << std::endl;
	std::cout << "|First Name	  ||	" << this->FirstName << std::endl;
	std::cout << "|Last Name	  ||	" << this->LastName << std::endl;
	std::cout << "|Nickname	  ||	" << this->NickName << std::endl;
	std::cout << "|Phone Number	  ||	" << this->PhoneNumber << std::endl;
	std::cout << "|Darkest Secret	  ||	" << this->DarkestSecret << std::endl;
	std::cout << "\\_________________/\\_________________/" << std::endl;
}
