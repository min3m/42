/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:42:12 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/11 11:30:03 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

int	end_heredoc_malloc(int fd, char *tmp)
{
	free(tmp);
	close(fd);
	return (-2);
}

int	end_heredoc_error(int fd, char *tmp)
{
	free(tmp);
	close(fd);
	return (-1);
}

int	end_heredoc(int fd, char *tmp)
{
	free(tmp);
	close(fd);
	return (1);
}
