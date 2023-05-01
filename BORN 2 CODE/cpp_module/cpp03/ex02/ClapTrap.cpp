/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:56:30 by youngmch          #+#    #+#             */
/*   Updated: 2023/05/01 18:31:21 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:_name("Unknown"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = source;
}

ClapTrap::ClapTrap(const std::string &name)
	:_name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap String Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const int &hp, const int &ep, const int &ad) //add at ex01
	:_name(name), _hit_point(hp), _energy_point(ep), _attack_damage(ad)
{
	std::cout << "ClapTrap Full Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Default Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &source)
{
	std::cout << "ClapTrap Copy Assignment called" << std::endl;
	if (this == &source)
		return (*this);
	this->_name = source.get_name();
	this->_hit_point = source.get_hp();
	this->_energy_point = source.get_ep();
	this->_attack_damage = source.get_ad();
	return (*this);
}

void ClapTrap::set_name(const std::string &name) { _name = name; }
void ClapTrap::set_hp(const int &hp) { _hit_point = hp; }
void ClapTrap::set_ep(const int &ep) { _energy_point = ep; }
void ClapTrap::set_ad(const int &ad) { _attack_damage = ad; }
std::string ClapTrap::get_name() const { return (this->_name); }
int ClapTrap::get_hp() const { return (this->_hit_point); }
int ClapTrap::get_ep() const { return (this->_energy_point); }
int ClapTrap::get_ad() const { return (this->_attack_damage); }

void ClapTrap::attack(const std::string &target)
{
	if (_energy_point && _hit_point > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		std::cout << "ClapTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << "'s EP is 0!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point <= 0)
		std::cout << "ClapTrap " << _name << " is already died!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
		_hit_point -= amount;
		if (_hit_point <= 0)
			std::cout << "ClapTrap " << _name << " die!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energy_point && _hit_point > 0)
	{
		std::cout << "ClapTrap " << _name << " reparing " << amount << " damage!" << std::endl;
		_hit_point += amount;
		_energy_point--;
	}
	else  if (_hit_point <= 0)
		std::cout << "ClapTrap " << _name << "'s already dead, he can't do anything!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << "'s EP is 0!" << std::endl;
}
