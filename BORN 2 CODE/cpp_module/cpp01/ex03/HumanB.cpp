/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:55:39 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 22:14:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
	:name("UNKNOWN"), weapon(NULL)
{
}

HumanB::HumanB(const std::string &name)
{
	this->name = name;
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (!weapon)
		std::cout << name << " don't have weapon, Plz set the weapon! " << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
