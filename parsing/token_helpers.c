/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:42 by abougati          #+#    #+#             */
/*   Updated: 2025/07/13 17:27:49 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_seperator(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_special(char c)
{
	return (c == '>' || c == '<' || c == '|');
}

int	get_special_token_len(char *line, int i)
{
	if ((line[i] == '<' || line[i] == '>') && line[i + 1] == line[i])
		return (2);
	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
		return (1);
	return (0);
}

int	get_word_token_len(char *line, int i)
{
	char	q;
	int		start;

	start = i;
	while (line[i] && !is_seperator(line[i]) && !is_special(line[i]))
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			q = line[i++];
			while (line[i] && line[i] != q)
				i++;
			if (line[i] == q)
				i++;
		}
		else
			i++;
	}
	return (i - start);
}

int	get_token_len(char *line, int i)
{
	int	len;

	while (line[i] && is_seperator(line[i]))
		i++;
	if (!line[i])
		return (0);
	len = get_special_token_len(line, i);
	if (len > 0)
		return (len);
	return (get_word_token_len(line, i));
}
