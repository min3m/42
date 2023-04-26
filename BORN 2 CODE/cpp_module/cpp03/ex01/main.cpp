/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:56:12 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/26 19:14:22 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap	a("JIM");
	ClapTrap	b;
	ClapTrap	c(a);
	ClapTrap	d;

	d = b;

	std::cout << "\n";
	std::cout << a;
	a.attack("Marine");
	std::cout << a;
	a.takeDamage(5);
	std::cout << a;
	a.beRepired(10);
	std::cout << a;
	a.takeDamage(100);
	std::cout << a;
	a.attack("JAX");
	a.takeDamage(100);
	a.beRepired(100);
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	return (0);
}
