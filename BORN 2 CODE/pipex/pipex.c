/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:21 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/10 21:44:20 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pipe(int start, int argc, char **argv, t_pipex pipex)
{
	int	i;

	i = start;
	while (i < argc - 2)
	{
		if (pipe(pipex.fd) < 0)
			exit_program("pipe", PERROR, EXIT_FAILURE);
		pipex.pid = fork();
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	pid_t	pid;

	if (argc < 5)
		exit_program("Wrong argument", ERROR, EXIT_FAILURE);
	pipex.infile = open(argv[0], O_RDONLY);
	if (pipex.infile < 0)
		exit_program(argv[0], PERROR, EXIT_FAILURE);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		exit_program(argv[argc - 1], PERROR, EXIT_FAILURE);
	pipex.path = find_path(argv, envp);
	get_pipe(2, argc, argv, pipex);
	return (0);
}
