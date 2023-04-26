/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:10:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/26 20:55:31 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap("Unknown", 100, 50, 20)
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap String Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source)
{
	std::cout << "ScavTrap String Constructor called" << std::endl;
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ClapTrap Default Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &source)
{
}
