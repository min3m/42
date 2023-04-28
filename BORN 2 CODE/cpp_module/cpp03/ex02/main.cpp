/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:56:12 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 17:59:38 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");
	FragTrap c("C");
	ScavTrap d("C");

	d.takeDamage(a.get_ad());
	d.takeDamage(a.get_ad());
	d.takeDamage(a.get_ad());
	d.takeDamage(a.get_ad());
	d.guardGate();
	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.get_ad());
	std::cout << std::endl;
	b.highFivesGuys();
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
	a.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
