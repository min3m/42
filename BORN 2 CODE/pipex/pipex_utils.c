/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:08:20 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/13 15:12:32 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fd)
{
	if (close(fd) == -1)
		exit_program("close()", PERROR, EXIT_FAILURE);
}

void	do_execve(char *cmd, char **cmd_split)
{
	execve(cmd, cmd_split, environ);
	exit_program(cmd, PERROR, EXIT_FAILURE);
}

void	free_split(char **cmd_split, char **path)
{
	int	i;

	i = -1;
	while (cmd_split[++i])
		free(cmd_split[i]);
	free(cmd_split);
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

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
	int		i;
	char	**path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		exit_program("ft_split error", PUTSTR, EXIT_FAILURE);
	i = 0;
	return (path);
}
