/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:26:15 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/13 16:52:26 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_env(t_env **env, char *key, char *val, char *arg)
{
	t_env	*node;
	char	*tmpval;

	if (!envget(*env, key))
	{
		node = newenv(arg, 0);
		add_envnode(env, node);
	}
	else if (val && ft_strcmp(val, envget(*env, key)->value) != 0)
	{
		tmpval = envget(*env, key)->value;
		envget(*env, key)->value = ft_strdup(val);
		if (tmpval)
			free(tmpval);
	}
	free(key);
	free(val);
}

void	export_err(char *err)
{
	if (!err)
		return ;
	write(2, err, ft_strlen(err));
	free(err);
}

int	check_key(char *arg)
{
	int		i;
	char	*error;

	if (!arg || !*arg)
		return (0);
	error = ft_strjoin(arg, " is not a valid identifier\n");
	if (arg[0] == '=')
		return (export_err(error), 0);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (i == 0 && !ft_isalpha(arg[i]) && arg[i] != '_')
			return (export_err(error), 0);
		else if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (export_err(error), 0);
		i++;
	}
	free(error);
	return (1);
}

void	ft_export(t_env **env, char **args)
{
	char **(split);
	char *(keyyy), *(vall);
	glob()->exit_status = 0;
	if (!args || !*args || !*args[0])
		return (noargs_export(*env));
	while (args && *args)
	{
		if (!check_key(*args))
		{
			args++;
			glob()->exit_status = 1;
			continue ;
		}
		split = ft_split(*args, '=');
		if (!split)
			return (free_args(split));
		keyyy = ft_strdup(split[0]);
		if (ft_strchr(*args, '='))
			vall = ft_strdup(ft_strchr(*args, '=') + 1);
		else
			vall = NULL;
		free_args(split);
		update_env(env, keyyy, vall, *args);
		args++;
	}
}

// printf("key=%s\tval=%s\n", keyyy, vall);// ### debuggin shit
