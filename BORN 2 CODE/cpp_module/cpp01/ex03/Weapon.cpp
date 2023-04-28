/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:21:42 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 22:36:34 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
	:weapon_type("frying pan")
{
}

Weapon::Weapon(const std::string &input)
	:weapon_type(input)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(const std::string& input)
{
	this->weapon_type = input;
}

const std::string &Weapon::getType() const
{
	return (this->weapon_type);
}
