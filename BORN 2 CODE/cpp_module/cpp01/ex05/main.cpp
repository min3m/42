/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:34:19 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 21:35:05 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::string	cmd;
	Harl		Harl;

	std::cout << "Insert command : ";
	std::getline(std::cin, cmd);
	Harl.complain(cmd);
	return (0);
}
