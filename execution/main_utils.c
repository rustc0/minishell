/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:09:59 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/15 16:54:32 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_global	*glob(void)
{
	static t_global	glob;

	return (&glob);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	inc_shlvl(t_env *env)
{
	int		shlvl;
	char	*tmp;
	char	*oldval;

	if (!env || !envget(env, "SHLVL"))
		return ;
	shlvl = (ft_atoi(envget(env, "SHLVL")->value)) + 1;
	tmp = ft_itoa(shlvl);
	oldval = envget(env, "SHLVL")->value;
	envget(env, "SHLVL")->value = ft_strdup(tmp);
	free(oldval);
	free(tmp);
}

char	**copyenv(t_env *envlist)
{
	t_env	*tmp;
	int		i;

	char *(tmp1), *(tmp2), **(res);
	if (!envlist)
		return (NULL);
	i = 0;
	tmp = envlist;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	res = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envlist)
	{
		tmp1 = ft_strjoin(envlist->key, "=");
		tmp2 = ft_strjoin(tmp1, envlist->value);
		free (tmp1);
		res[i++] = tmp2;
		envlist = envlist->next;
	}
	res[i] = NULL;
	return (res);
}

void	clean_env(t_env **head)
{
	t_env	*tmp;
	t_env	*nxt;

	tmp = *head;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = nxt;
	}
}
