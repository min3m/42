/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:52:58 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 22:33:58 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  {
    Weapon club = Weapon();
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("holly spiked club!");
    bob.attack();
  }
  // {
  //   Weapon club = Weapon("crude spiked club");
  //   HumanB jim("Jim");
  //   jim.setWeapon(club);
  //   jim.attack();
  //   club.setType("mother's smashed club!");
  //   jim.attack();
  // }
  return (0);
}
