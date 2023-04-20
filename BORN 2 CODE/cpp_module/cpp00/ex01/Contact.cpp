/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:46:24 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/20 16:55:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _first_name(""), _last_name(""), _nick_name(""), _phone_number(""), _secret("")
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
std::string Contact::get_first()
{
	return (this->_first_name);
}
std::string Contact::get_last()
{
	return (this->_last_name);
}
std::string Contact::get_nick()
{
	return (this->_nick_name);
}
std::string Contact::get_number()
{
	return (this->_phone_number);
}
std::string Contact::get_secret()
{
	return (this->_secret);
}
