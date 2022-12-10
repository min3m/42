/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:36:36 by youngmch          #+#    #+#             */
/*   Updated: 2022/12/10 21:41:42 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //perror
# include <string.h> //strerror 쓸 필요 없을거가타
# include "libft/libft.h"

# define PERROR 0
# define ERROR 1

typedef struct	s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;
	char	**path;
}				t_pipex;

char	**find_path(char **argv, char **envp);
void	get_pipe(int start, int argc, char **argv, t_pipex pipex);


// extern char	**environ;

#endif
