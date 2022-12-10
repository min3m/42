/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:08:20 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/10 21:41:09 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_program(char *message, int error, int status)
{
	if (error == PERROR)
		perror(message);
	else
		ft_putendl_fd(message, STDERR_FILENO);
	exit(status);
}

char	**find_path(char **argv, char **envp)
{
	char	**path;

	while (!ft_strnstr(*envp, "PATH", ft_strlen(*envp)))
		envp++;
	path = ft_split(*envp + 5, ':');
	return (path);
}
