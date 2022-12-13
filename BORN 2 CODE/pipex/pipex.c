/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:44:21 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/13 19:46:20 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_program(char *argv_cmd, t_pipex *pipex)
{
	int		i;
	char	*tmp;
	char	**cmd_split;

	cmd_split = ft_split(argv_cmd, ' ');
	if (!access(cmd_split[0], F_OK | X_OK))
		do_execve(cmd_split[0], cmd_split);
	i = -1;
	while (pipex->path[++i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		pipex->path_cmd = ft_strjoin(tmp, cmd_split[0]);
		free(tmp);
		if (!access(pipex->path_cmd, F_OK | X_OK))
			do_execve(pipex->path_cmd, cmd_split);
		free(pipex->path_cmd);
	}
	ft_putstr_fd(cmd_split[0], STDERR_FILENO);
	free_split(cmd_split, pipex->path);
	exit_program(": command not found\n", PUTSTR, COMMAND_NOT_FOUND);
}

void	pipe_and_fork(char *argv, t_pipex *pipex, int is_last)
{
	int	pid;

	if (pipe(pipex->fd) == -1)
		exit_program("pipe()", PERROR, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit_program("fork()", PERROR, EXIT_FAILURE);
	if (pid == 0)
	{
		if (!is_last)
		{
			dup2(pipex->fd[1], STDOUT_FILENO);
			close(pipex->fd[0]);
			close(pipex->fd[1]);
		}
		execve_program(argv, pipex);
	}
	else
	{
		if (is_last)
			pipex->lst_pid = pid;
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
	}
}

void	do_pipex(int start, int argc, char **argv, t_pipex *pipex)
{
	int	i;
	int	status;

	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	i = start;
	while (i < argc - 2)
		pipe_and_fork(argv[i++], pipex, 0);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	pipe_and_fork(argv[i], pipex, 1);
	while (i >= start)
	{
		if (pipex->lst_pid == wait(&status))
			pipex->lst_status = status;
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	pid_t	pid;

	if (argc != 5)
		exit_program("Wrong argument", PUTSTR, EXIT_FAILURE);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		perror(argv[1]);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		exit_program(argv[argc - 1], PERROR, EXIT_FAILURE);
	pipex.path = find_path(argv, environ);
	do_pipex(2, argc, argv, &pipex);
	return ((pipex.lst_status >> 8) & 0xFF);
}
