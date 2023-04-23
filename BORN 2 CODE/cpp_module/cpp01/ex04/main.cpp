/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:42:57 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 17:16:30 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong File Arguments!" << std::endl;
		return (1);
	}
	std::string		filename(argv[1]);
	std::string		toFind(argv[2]);
	std::string		toReplace(argv[3]);
	std::ifstream	read_file(filename);
	std::ofstream	write_file(filename + ".replace");
	if (!read_file.is_open() || !write_file.is_open())
	{
		std::cout << "File open error!" << std::endl;
		return (1);
	}
	std::string	line;
	while (std::getline(read_file, line))
	{
		int	index = line.find(toFind);
		while (index != -1)
		{
			line.insert(index, toReplace);
			line.erase(index + toReplace.length(), toFind.length());
			index = line.find(toFind, index + toFind.length());
		}
		write_file << line << std::endl;
	}
	read_file.close();
	write_file.close();
	return (0);
}
