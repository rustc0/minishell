/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:25:15 by rahmoham          #+#    #+#             */
/*   Updated: 2025/06/16 17:55:50 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_env_node(t_env *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}

int	ft_unset(char **keys, t_env **env)
{
	t_env	*prev;
	t_env	*curr;

	while (*keys)
	{
		prev = NULL;
		curr = *env;
		while (curr)
		{
			if (ft_strcmp(curr->key, *keys) == 0)
			{
				if (prev == NULL)
					*env = curr->next;
				else
					prev->next = curr->next;
				free_env_node(curr);
				break ;
			}
			prev = curr;
			curr = curr->next;
		}
		keys++;
	}
	return (0);
}
