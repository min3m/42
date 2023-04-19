/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:46:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/19 22:12:52 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}
void	Contact::set_first(std::string _first_name)
{
	this->_first_name = _first_name;
}
void	Contact::set_last(std::string _last_name)
{
	this->_last_name = _last_name;
}
void	Contact::set_nick(std::string _nick_name)
{
	this->_nick_name = _nick_name;
}
void	Contact::set_number(std::string _phone_number)
{
	this->_phone_number = _phone_number;
}
void	Contact::set_secret(std::string _secret)
{
	this->_secret = _secret;
}
