/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:48:16 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/22 21:41:45 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "address of the string variable : " << &brain << std::endl;
	std::cout << "address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "address held by stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "value of the string variable : " << brain << std::endl;
	std::cout << "value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF : " << stringREF << std::endl;

	return (0);
}
