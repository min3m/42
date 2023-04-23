/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:53:18 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 14:28:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string weapon_type;
public:
	Weapon();
	Weapon(const std::string &input);
	~Weapon();
	void setType(const std::string &input);
	const std::string &getType() const;
};

#endif
