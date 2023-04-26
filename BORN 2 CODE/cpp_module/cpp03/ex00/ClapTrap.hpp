/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:54:20 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/26 20:47:10 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_hit_point;
	int			_energy_point;
	int			_attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &source);
	~ClapTrap();
	ClapTrap& operator = (const ClapTrap& source);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepired(unsigned int amount);
	std::string get_name() const;
	int get_hp() const;
	int get_ep() const;
	int get_ad() const;
	void set_name(const std::string &name);
	void set_hp(const int &hp);
	void set_ep(const int &ep);
	void set_ad(const int &ad);
};

std::ostream &operator << (std::ostream &out, const ClapTrap &source);

#endif
