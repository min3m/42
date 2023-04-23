/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:34:19 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 21:40:08 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong Arguments!" << std::endl;
		return (1);
	}
	std::string	cmd;
	Harl		karen;

	cmd = argv[1];
	karen.complain(cmd);
	return (0);
}
