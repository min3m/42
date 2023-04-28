/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:42:29 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 17:55:07 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap("Unknown", 100, 100, 30)
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap String Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &source)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = source;
}

FragTrap &FragTrap::operator = (const FragTrap &source)
{
	std::cout << "FragTrap Copy Assingment called" << std::endl;
	if (this == &source)
		return (*this);
	this->set_name(source.get_name());
	this->set_hp(source.get_hp());
	this->set_ep(source.get_ep());
	this->set_ad(source.get_ad());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Default Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energy_point && _hit_point > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point < 0)
		std::cout << "FragTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "FragTrap " << _name << "'s EP is 0!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hit_point <= 0)
		std::cout << "FragTrap " << _name << " is already died!" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " takes " << amount << " damage!" << std::endl;
		_hit_point -= amount;
		if (_hit_point <= 0)
			std::cout << "FragTrap " << _name << " die!" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if(_energy_point && _hit_point > 0)
	{
		std::cout << "FragTrap " << _name << " reparing " << amount << " damage!" << std::endl;
		_hit_point += amount;
		_energy_point--;
	}
	else  if (_hit_point < 0)
		std::cout << "FragTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "FragTrap " << _name << "'s EP is 0!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (_energy_point > 0 && _hit_point > 0)
		std::cout << "FragTrap " << get_name() << " asks positive five " << std::endl;
	else
		std::cout << "FragTrap " << get_name() << " can't asks positive five " << std::endl;
}
