/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:09 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/12 20:01:39 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //perror
# include "libft/libft.h"

# define PERROR 0
# define ERROR 1

typedef struct	s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		lst_pid;
	int		lst_status;
	int		is_heredoc;
	pid_t	pid;
	char	**path;
	char	*path_cmd;
}				t_pipex;

void	is_here_doc(char **argv, t_pipex pipex);
void	do_pipex(int start, int argc, char **argv, t_pipex *pipex);
void	pipe_and_fork(char *argv, t_pipex *pipex, int is_last);
void	execve_program(char *argv_cmd, t_pipex *pipex);
char	**find_path(char **argv, char **envp);
void	do_execve(char *cmd, char **cmd_split);
void	free_split(char **cmd_split, char **path);
void	exit_program(char *message, int error, int status);
void	close_fd(int fd);


extern char	**environ;

#endif
