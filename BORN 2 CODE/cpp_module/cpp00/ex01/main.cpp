/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:23:01 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/25 17:06:56 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	prompt(const std::string message, std::string &buf)
{
	std::cout << message;
	while (std::getline(std::cin, buf) && buf.empty())
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
	prompt("Darkest Secret : ", buf);
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
			break ;
		else if (cmd == "ADD")
			phonebook.add_contact(get_contact(), index++ % 8);
		else if (cmd == "SEARCH")
		{
			if (!index)
				std::cout << "Phonebook is empty, Plz register something!" << std::endl;
			else
			{
				phonebook.print_contact(index);
				while (true)
				{
					prompt("Which Index do you want to See? : ", cmd);
					int	num = std::atoi(cmd.c_str());
					if (cmd.size() == 1 && (num > 0 && num < 9) && num <= index)
					{
						phonebook.show_contact(num - 1);
						break ;
					}
					std::cout << "It's not valid number, Try again" << std::endl;
				}
			}
		}
	}
	return (0);
}
