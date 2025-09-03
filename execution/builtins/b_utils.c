/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:38:09 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/10 17:18:35 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_ac(char **args)
{
	int	ac;

	ac = 0;
	if (!args || !*args)
		return (0);
	while (*args)
	{
		args++;
		ac++;
	}
	return (ac);
}

t_env	*sort_env(t_env *env)
{
	char *(temp_key), *(temp_value);
	t_env *(sorted), *(current), *(next);
	sorted = env;
	if (!env)
		return (NULL);
	current = sorted;
	while (current && current->next)
	{
		next = current->next;
		while (next)
		{
			if (ft_strcmp(current->key, next->key) > 0)
			{
				temp_key = current->key;
				temp_value = current->value;
				current->key = next->key;
				current->value = next->value;
				next->key = temp_key;
				next->value = temp_value;
			}
			next = next->next;
		}
		current = current->next;
	}
	return (sorted);
}

void	noargs_export(t_env *env)
{
	t_env	*sorted;

	sorted = sort_env(env);
	if (!sorted)
		return ;
	while (sorted)
	{
		if (sorted->key && sorted->value)
			printf("declare -x %s=\"%s\"\n", sorted->key, sorted->value);
		else
			printf("declare -x %s\n", sorted->key);
		sorted = sorted->next;
	}
}

t_env	*envget(t_env *env, char *key)
{
	t_env	*current;

	if (!env || !key)
		return (NULL);
	current = env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

unsigned long long	ft_atoull(char *str)
{
	unsigned long long	res;

	int (i), (n);
	i = 0;
	n = 1;
	res = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > LONG_MAX)
			return (ULLONG_MAX);
	}
	return (res * n);
}
