/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:01:34 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 13:13:38 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
	:name("UNKNOWN")
{
}

Zombie::Zombie(const std::string& input)
	: name(input)
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is died" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::set_name(const std::string& name_in)
{
	this->name = name_in;
}
