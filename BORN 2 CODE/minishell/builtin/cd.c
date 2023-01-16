/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:15:28 by marvin            #+#    #+#             */
/*   Updated: 2023/01/05 00:15:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_minishell;

void	change_pwd(char *path)
{
	char	*pwd;
	t_env	*curr;

	pwd = ft_strdup(ft_getenv("PWD"));
	curr = g_minishell.env;
	while (curr->next)
	{
		if (!ft_strncmp(curr->next->data, "PWD", 3))
			change_envnode(&curr, "PWD=", path);
		else if (!ft_strncmp(curr->next->data, "OLDPWD", 6))
			change_envnode(&curr, "OLDPWD=", pwd);
		curr = curr->next;
	}
	ft_free(pwd);
}

int	do_cd(char **argv)
{
	char		*pwd;
	struct stat	buf;

	pwd = NULL;
	if (stat(argv[1], &buf) != -1 && (S_IFMT & buf.st_mode) != S_IFDIR)
		return (error_builtin_cd(": cd:", argv[1], ": Not a directory"));
	else if (access(argv[1], X_OK) == -1 && access(argv[1], F_OK) == 0)
		return (error_builtin_cd("cd: ", argv[1], ": Permision denied"));
	else if (chdir(argv[1]) == -1)
		return (error_builtin_cd(": cd: ", argv[1],
				": No such file or directory"));
	pwd = getcwd(NULL, 0);
	change_pwd(pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}

int	ft_cd(char **argv)
{
	char	*home;

	home = ft_getenv("HOME");
	if (argv[1] && argv[1][0] == '-')
	{
		ft_putendl_fd("cd: options should not be included", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if ((!argv[1] && !home) || (argv[1] && argv[1][0] == '~' && !home))
		return (error_builtin_cd(": cd:", "HOME", "not set"));
	if (!argv[1] || (argv[1] && argv[1][0] == '~'))
	{
		if (chdir(home) == -1)
			return (error_builtin_cd(": cd: ", "HOME",
					": No such file or directory"));
		change_pwd(home);
	}
	else
		do_cd(argv);
	return (EXIT_SUCCESS);
}
