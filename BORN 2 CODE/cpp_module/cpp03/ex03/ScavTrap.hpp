/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:10:32 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/28 17:36:24 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap& source);
	~ScavTrap();
	ScavTrap &operator = (const ScavTrap& source);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
};

std::ostream &operator << (std::ostream &out, const ScavTrap &source);

#endif
