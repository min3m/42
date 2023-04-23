/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:28:10 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/22 19:33:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	N(10);

	Zombie *hordes = zombieHorde(N, "Zomboid");

	for (int i = 0; i < N; i++)
		hordes[i].announce();
	delete [] hordes;
	return (0);
}
