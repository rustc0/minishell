/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:12 by abougati          #+#    #+#             */
/*   Updated: 2025/07/13 15:14:35 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_tokens(char *line)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (line[i])
	{
		len = get_token_len(line, i);
		if (len == 0)
			break ;
		count++;
		i += len;
	}
	return (count);
}

int	count_cmdargs(char **tokens, t_tokens *types)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i] && types[i] != PIPE && types[i] != NULL_TOK)
	{
		if (types[i] == WORD && (i == 0 || (types[i - 1] != INDIR
					&& types[i - 1] != OUTDIR && types[i - 1] != HEREDOC
					&& types[i - 1] != APPEND)))
			count++;
		i++;
	}
	return (count);
}

int	count_files(char **tokens, t_tokens *types)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i] && types[i] != PIPE && types[i] != NULL_TOK)
	{
		if (types[i] == INDIR || types[i] == HEREDOC
			|| types[i] == OUTDIR || types[i] == APPEND)
			count++;
		i++;
	}
	return (count);
}
