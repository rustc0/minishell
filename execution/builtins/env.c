/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:57:51 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/10 19:11:18 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*newenv(char *env, int hid)
{
	t_env	*node;
	char	**env_parts;

	(void)hid;
	env_parts = ft_split((char *)env, '=');
	if (!env_parts || !env_parts[0])
		return (free(env_parts), NULL);
	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (free_args(env_parts), NULL);
	node->key = ft_strdup(env_parts[0]);
	if (ft_strchr(env, '='))
		node->value = ft_strdup(ft_strchr(env, '=') + 1);
	else
		node->value = NULL;
	free_args(env_parts);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_env	*envlast(t_env *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_envnode(t_env **head, t_env *new)
{
	t_env	*node;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	node = envlast(*head);
	node->next = new;
	new->prev = node;
}

t_env	*init_env(char **env)
{
	t_env	*envcpy;
	int		total_length;
	int		i;

	total_length = 0;
	if (!env || !*env)
		return (NULL);
	while (env[total_length])
		total_length++;
	envcpy = newenv(env[0], 0);
	i = 1;
	while (i < total_length)
		add_envnode(&envcpy, newenv(env[i++], 0));
	return (envcpy);
}

int	ft_env(t_env *env, int ac)
{
	t_env	*current;

	if (ac > 1)
	{
		write(2, "env: too many arguments\n", 24);
		return (1);
	}
	if (!env)
		return (1);
	current = env;
	while (current)
	{
		if (current->key && (current->value
				|| ft_strcmp(current->value, "") == 0))
			printf("%s=%s\n", (char *)current->key, (char *)current->value);
		current = current->next;
	}
	return (0);
}
