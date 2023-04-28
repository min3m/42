/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:56:12 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 16:34:32 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap	a("A");
	ScavTrap	b("B");
	ScavTrap	c("C");
	ScavTrap	d;

	d = c;


	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.get_ad());
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(b.get_ad());
	std::cout << std::endl;
	c.attack("B");
	b.takeDamage(c.get_ad());
	std::cout << std::endl;
	b.beRepaired(25);
	std::cout << std::endl;
	a.beRepaired(25);
	std::cout << std::endl;
	a.guardGate();
	std::cout << std::endl;

	return (0);
}
