/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:54:26 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 21:35:14 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	unlink_heredoc(void)
{
	char			*str;
	DIR				*dir_ptr;
	struct dirent	*file;

	dir_ptr = NULL;
	file = NULL;
	dir_ptr = opendir("./here_doc");
	if (dir_ptr == NULL)
		return ;
	file = readdir(dir_ptr);
	file = readdir(dir_ptr);
	file = readdir(dir_ptr);
	while (file != NULL)
	{
		str = ft_strjoin("./here_doc/", file->d_name);
		unlink(str);
		ft_free(str);
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
}

int	is_cmd_line_valid(char *cmd_line)
{
	size_t	i;

	i = 0;
	while (cmd_line[i] == ' ')
		i++;
	if (i == ft_strlen(cmd_line))
		return (0);
	return (1);
}

char	*ft_getenv(char *dest)
{
	t_env	*curr;
	char	*str;
	size_t	len;

	str = NULL;
	curr = g_minishell.env;
	len = ft_strlen(dest);
	while (curr)
	{
		if (!ft_strncmp(curr->data, dest, len) && *(curr->data + len) == '=')
		{
			str = curr->data + len + 1;
			break ;
		}
		curr = curr->next;
	}
	return (str);
}

int	global_init(char **env)
{
	int	i;

	g_minishell.last_state = 0;
	g_minishell.bp_stdin = dup(STDIN_FILENO);
	g_minishell.bp_stdout = dup(STDOUT_FILENO);
	g_minishell.shell_name = "kiwishell";
	i = -1;
	g_minishell.env = NULL;
	while (env[++i])
	{
		if (!add_env(&(g_minishell.env), env[i], 0))
			error_env(&(g_minishell.env), NULL);
	}
	return (1);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	res[0] = 0;
	ft_strlcat(res, s1, len1 + len2 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	ft_free(s1);
	return (res);
}
