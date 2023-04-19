/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:23:01 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/19 22:12:48 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	prompt(const std::string message, std::string &cmd)
{
	std::cout << message;
	while (std::getline(std::cin, cmd) && cmd.empty())
	{
		std::cout << "You should write something, Try again" << std::endl;
		std::cout << message;
	}
}

Contact	get_contact()
{
	Contact		temp;
	std::string	buf;

	prompt("First name : ", buf);
	temp.set_first(buf);
	prompt("Last name : ", buf);
	temp.set_last(buf);
	prompt("Nick name : ", buf);
	temp.set_nick(buf);
	prompt("Phone Number : ", buf);
	temp.set_number(buf);
	prompt("Secret : ", buf);
	temp.set_secret(buf);
	return (temp);
}

int	main()
{
	std::string	cmd;
	int			index;
	PhoneBook	phonebook;

	index = 0;
	while (true)
	{
		prompt("Plz, Write your CMD! (ADD, SEARCH, EXIT) : ", cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
		{
			phonebook.add_contact(get_contact(), index++ % 8);
		}
		else if (cmd == "SEARCH")
		{
			// std::cout
		}
	}
	return (0);
}
