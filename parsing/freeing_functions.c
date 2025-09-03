/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:55:10 by abougati          #+#    #+#             */
/*   Updated: 2025/07/15 17:57:27 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_files(t_files *files)
{
	int	i;

	if (!files)
		return ;
	i = 0;
	while (files->files && files->files[i])
	{
		if (files->types[i] == HEREDOC)
			unlink(files->files[i]);
		else
			free(files->files[i]);
		i++;
	}
	free(files->files);
	free(files->types);
	free(files);
}

void	free_list(t_shell *head)
{
	t_shell	*tmp;

	while (head)
	{
		tmp = head->next;
		free_tokens(head->args);
		free_files(head->files);
		free(head);
		head = tmp;
	}
}
