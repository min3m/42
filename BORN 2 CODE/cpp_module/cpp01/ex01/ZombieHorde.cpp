/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:02:57 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/22 19:36:47 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombie_horde = new Zombie[N];

	for(int i = 0; i < N; i++)
		zombie_horde[i].set_name(name);
	return (zombie_horde);
}
