/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:01:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 13:12:12 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(const std::string& input);
	~Zombie();
	void announce(void);
	void set_name(const std::string& name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
