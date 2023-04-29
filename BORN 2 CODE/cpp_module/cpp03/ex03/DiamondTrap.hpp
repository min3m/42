/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:18:00 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/28 17:39:02 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:

public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap& source);
	DiamondTrap& operator = (const DiamondTrap& source);
	~DiamondTrap();
	void whoAmI();
};


#endif
