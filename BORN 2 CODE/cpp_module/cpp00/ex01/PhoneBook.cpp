/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:38:38 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/20 19:00:51 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact(Contact temp, int index)
{
	this->contact[index] = temp;
}

void	PhoneBook::print_contact(int index)
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nick Name" << "|" << std::endl;
	if (index > 8)
		index = 8;
	for (int i = 0; i < index; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		print_to_width(contact[i].get_first());
		print_to_width(contact[i].get_last());
		print_to_width(contact[i].get_nick());
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::print_to_width(std::string _str)
{
	if (_str.size() > 10)
	{
		std::cout << "|" << std::setw(9) << _str.substr(0, 9) << ".";
	}
	else
		std::cout << "|" << std::setw(10) << _str;
}

void	PhoneBook::show_contact(int index)
{
	std::cout <<  "First NAME : " << contact[index].get_first() << std::endl;
	std::cout <<  "Last NAME : " << contact[index].get_last() << std::endl;
	std::cout <<  "Nick NAME : " << contact[index].get_nick() << std::endl;
	std::cout <<  "Phone Number : " << contact[index].get_number() << std::endl;
	std::cout <<  "Darkest Secret : " << contact[index].get_secret() << std::endl;
}
