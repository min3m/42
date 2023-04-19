/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:43:27 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/19 22:12:51 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _secret;
public:
	Contact();
	~Contact();
	void set_first(std::string _first_name);
	void set_last(std::string _last_name);
	void set_nick(std::string _nick_name);
	void set_number(std::string _phone_number);
	void set_secret(std::string _secret);
};

#endif
