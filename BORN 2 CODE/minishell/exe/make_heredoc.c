/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:42:12 by dongyoki          #+#    #+#             */
/*   Updated: 2023/01/12 10:33:35 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	make_heredoc(t_parse **lst, t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur && cur->state != DENY)
		here_doc_loop1(lst, cmd, &cur);
}

void	here_doc_loop1(t_parse **lst, t_cmd **cmd, t_cmd **cur)
{
	int	i;
	int	flag;

	i = 0;
	while ((*cur)->red[i].red)
	{
		if ((*cur)->red[i].red[1] == '<')
		{
			flag = make_heredoc_file((*cur)->red[i].file, (*cur)->num);
			if (flag == 1)
				error_strerror(lst, cmd);
			else if (flag == 2)
				error_cmd(lst, cmd);
		}
		i++;
	}
	(*cur) = (*cur)->next;
}

int	make_heredoc_file(char *file, int num)
{
	char	*filename;
	char	*tmp;
	int		fd;
	int		flag;

	tmp = strjoin_ascii(file, num);
	if (!tmp)
		return (1);
	filename = ft_strjoin("./here_doc/", tmp);
	free(tmp);
	if (!filename)
		return (1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(filename);
	if (fd < 0)
		return (1);
	flag = check_heredoc(fd, file);
	return (flag);
}

int	check_heredoc(int fd, char *file)
{
	int	flag;

	while (1)
	{
		flag = here_doc_loop2(fd, file);
		if (flag == 1)
			return (0);
		else if (flag == -1)
			return (1);
		else if (flag == -2)
			return (2);
	}
	return (0);
}

int	here_doc_loop2(int fd, char *file)
{
	char	*dollar;
	char	*tmp;

	tmp = readline("> ");
	if (!tmp)
		return (0);
	if (ft_strcmp(file, tmp) == 0)
		return (end_heredoc(fd, tmp));
	dollar = here_doc_dollar(tmp);
	if (!dollar)
		return (end_heredoc_malloc(fd, tmp));
	if (write(fd, dollar, ft_strlen(dollar)) != (ssize_t)ft_strlen(dollar))
	{
		free(dollar);
		return (end_heredoc_error(fd, tmp));
	}
	free(dollar);
	if (write(fd, "\n", 1) != 1)
		return (end_heredoc_error(fd, tmp));
	free(tmp);
	return (0);
}
