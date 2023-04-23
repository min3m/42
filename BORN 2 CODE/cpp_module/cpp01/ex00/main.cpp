/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:35:39 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/22 18:53:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	foo1("foo1");
	Zombie	*heap_zombie = newZombie("Heap Zombie");
	foo1.announce();
	heap_zombie->announce();
	randomChump("Stack Zombie");
	delete heap_zombie;
	return (0);
}
