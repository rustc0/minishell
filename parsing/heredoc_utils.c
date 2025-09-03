/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:23:10 by abougati          #+#    #+#             */
/*   Updated: 2025/07/15 18:10:22 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_tab3aha(char *eof)
{
	int	i;

	i = 0;
	while (eof[i])
	{
		if ((eof[i] == '\'' && eof[i + 1] == '\'')
			|| (eof[i] == '"' && eof[i + 1] == '"'))
			return (1);
		else if (eof[i] == '\'' && eof[i + 1] == '"' && eof[i + 2] == '\'')
			return (1);
		else if (eof[i] == '"' && eof[i + 1] == '\'' && eof[i + 2] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	is_quoted(char *eof)
{
	size_t	i;

	if (!eof)
		return (0);
	i = ft_strlen(eof);
	if (i < 2)
		return (0);
	if ((eof[0] == '\'' && eof[i - 1] == '\'')
		|| (eof[0] == '"' && eof[i - 1] == '"'))
		return (1);
	else if ((eof[0] == '\'' || eof[0] == '"')
		|| (eof[i - 1] == '\'' || eof[i - 1] == '"'))
		return (1);
	else if (is_tab3aha(eof))
		return (1);
	return (0);
}

char	*fix_eof(char *input)
{
	char	*result;

	int (i), (in_single), (in_double);
	result = ft_calloc(1, 1);
	i = 0;
	in_single = 0;
	in_double = 0;
	while (input[i])
	{
		if (input[i] == '$'
			&& (input[i + 1] == '\'' || input[i + 1] == '"'))
			i++;
		if ((input[i] == '\'' && !in_double) || (input[i] == '"' && !in_single))
		{
			if (input[i] == '\'' && !in_double)
				in_single = !in_single;
			else if (input[i] == '"' && !in_single)
				in_double = !in_double;
			i++;
		}
		else
			result = append_char(result, input[i++]);
	}
	return (result);
}

char	*expand_line(char *input)
{
	char	*result;
	int		i;

	result = ft_calloc(1, 1);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
			handle_dollar(input, &i, &result);
		else
			result = append_char(result, input[i++]);
	}
	free(input);
	return (result);
}
