/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:10:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/05/01 18:34:18 by youngmch         ###   ########.fr       */
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
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &source)
{
	std::cout << "ScavTrap Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->set_name(source.get_name());
	this->set_hp(source.get_hp());
	this->set_ep(source.get_ep());
	this->set_ad(source.get_ad());
	return (*this);
}

std::ostream &operator << (std::ostream &out ,const ScavTrap &source)
{
	out << "Name : " << source.get_name() << std::endl;
	out << "HP : " << source.get_hp() << std::endl;
	out << "EP : " << source.get_ep() << std::endl;
	out << "AD : " << source.get_ad() << std::endl;
	return (out);
}

void ScavTrap::attack(const std::string &target)
{
	if (_energy_point && _hit_point > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		std::cout << "ScavTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << "'s EP is 0!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hit_point <= 0)
		std::cout << "ScavTrap " << _name << " is already died!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " takes " << amount << " damage!" << std::endl;
		_hit_point -= amount;
		if (_hit_point <= 0)
			std::cout << "ScavTrap " << _name << " die!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if(_energy_point && _hit_point > 0)
	{
		std::cout << "ScavTrap " << _name << " reparing " << amount << " damage!" << std::endl;
		_hit_point += amount;
		_energy_point--;
	}
	else  if (_hit_point <= 0)
		std::cout << "ScavTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << "'s EP is 0!" << std::endl;
}


void ScavTrap::guardGate()
{
	if (_energy_point > 0 && _hit_point > 0)
		std::cout << "ScavTrap is now on Gate Keeper mode" << std::endl;
	else
		std::cout << "ScavTrap can't turn on Gate Keeper mode" << std::endl;
}
