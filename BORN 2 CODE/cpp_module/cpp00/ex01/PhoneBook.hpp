/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:38:40 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/20 18:48:31 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void add_contact(Contact temp, int index);
	void print_contact(int index);
	void print_to_width(std::string _str);
	void show_contact(int index);
};

#endif
