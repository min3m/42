/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:30:23 by youngmch          #+#    #+#             */
/*   Updated: 2023/01/11 15:30:23 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

char	*get_pwd_line(char *line, char *pwd_line)
{
	int	i;
	int	count;

	i = ft_strlen(pwd_line) - 1;
	count = 0;
	while (pwd_line[i] && i > 0)
	{
		if (pwd_line[i] == '/')
		{
			count++;
			if (count == 2 && i != 0)
			{
				line = ft_strjoin_free(line, "~");
				if (!line)
					return (0);
				break ;
			}
		}
		i--;
	}
	line = ft_strjoin_free(line, pwd_line + i);
	if (!line)
		return (0);
	return (line);
}

char	*find_pwd(char *line)
{
	t_env	*curr;

	curr = g_minishell.env;
	while (curr)
	{
		if (!ft_strncmp(curr->data, "PWD", ft_strlen("PWD")))
		{
			line = get_pwd_line(line, curr->data + 4);
			if (!line)
				return (0);
			break ;
		}
		curr = curr->next;
	}
	return (line);
}

char	*get_prompt_line(char *line)
{
	t_env	*curr;

	curr = g_minishell.env;
	line = ft_strdup("");
	if (!line)
		error_init();
	while (curr)
	{
		if (!ft_strncmp(curr->data, "USER", ft_strlen("USER")))
		{
			line = ft_strjoin_free(line, curr->data + 5);
			if (!line)
				return (0);
		}
		curr = curr->next;
	}
	line = ft_strjoin_free(line, ":");
	if (!line)
		return (0);
	line = find_pwd(line);
	return (line);
}

char	*make_prompt(char *prompt)
{
	char	*line;

	line = NULL;
	prompt = ft_strdup("\033[1m\033[32m");
	if (!prompt)
		error_init();
	line = get_prompt_line(line);
	if (!line)
		error_prompt_line(prompt);
	prompt = ft_strjoin_free(prompt, line);
	if (!prompt)
	{
		ft_free(line);
		error_prompt_line(prompt);
	}
	prompt = ft_strjoin_free(prompt, "$ \033[0m");
	if (!prompt)
		error_prompt_line(prompt);
	ft_free(line);
	return (prompt);
}

void	prompt(void)
{
	t_shell	shell;
	char	*prompt;

	prompt = NULL;
	while (1)
	{
		signal_init();
		prompt = make_prompt(prompt);
		shell.cmd_line = readline(prompt);
		if (!(shell.cmd_line))
			handle_ctrl_d(EXIT_SUCCESS);
		else if (*(shell.cmd_line) != '\0')
		{
			add_history(shell.cmd_line);
			if (is_cmd_line_valid(shell.cmd_line))
			{
				execute(shell.cmd_line);
				unlink_heredoc();
			}
		}
		dup2_std_to_bp();
		free(shell.cmd_line);
		ft_free(prompt);
		shell.cmd_line = NULL;
	}
}
