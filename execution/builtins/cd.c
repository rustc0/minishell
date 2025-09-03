/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:21:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/16 12:46:18 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*tilde_exp(char *str)
{
	char	*home;
	char	*ret;

	home = NULL;
	if (!str || *str != '~')
		return (NULL);
	if (envget(glob()->env, "HOME"))
		home = envget(glob()->env, "HOME")->value;
	ret = ft_strjoin(home, ft_strchr(str, '/'));
	free(str);
	return (ret);
}

int	changedir(char **args)
{
	char	*home;

	if (args[1] && args[1][0] == '~')
		args[1] = tilde_exp(args[1]);
	if (!args[1])
	{
		if (!envget(glob()->env, "HOME") || !envget(glob()->env, "HOME")->value)
		{
			write(2, "cd: HOME is not set\n", 21);
			return (1);
		}
		home = envget(glob()->env, "HOME")->value;
		chdir(home);
	}
	else if (chdir(args[1]) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

void	setnewvars(char *pwd, char *oldpwd)
{
	char	**args;
	char	*old;
	char	*curr;

	old = ft_strjoin("OLDPWD=", oldpwd);
	curr = ft_strjoin("PWD=", pwd);
	args = ft_split(old, ' ');
	if (!args)
		return ;
	ft_export(&glob()->env, args);
	free_args(args);
	args = ft_split(curr, ' ');
	ft_export(&glob()->env, args);
	free_args(args);
	free(old);
	free(curr);
}

int	ft_cd(char **args, int ac)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (ac > 2)
	{
		write(2, "cd: too many arguments\n", 24);
		free(oldpwd);
		return (1);
	}
	if (changedir(args))
		return (free(oldpwd), 1);
	pwd = getcwd(NULL, 0);
	setnewvars(pwd, oldpwd);
	free(oldpwd);
	free(pwd);
	return (0);
}
