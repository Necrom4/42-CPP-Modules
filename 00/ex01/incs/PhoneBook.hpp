/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:03:15 by dferreir          #+#    #+#             */
/*   Updated: 2023/06/01 10:29:53 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
		Contact	Contacts[9];

	public:
		PhoneBook();
		~PhoneBook();
		void	Start(void);
		void	AddContact(void);
		void	PrintContactsList(void);
		void	PrintContactInfo(void);
		std::string	PrintCase(std::string str);
		int		ValidInput(std::string str);
};

#endif
