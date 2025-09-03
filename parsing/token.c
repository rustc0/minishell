/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:45 by abougati          #+#    #+#             */
/*   Updated: 2025/07/13 19:03:52 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_token(char *line, int *i)
{
	int		len;
	char	*token;

	while (line[*i] && is_seperator(line[*i]))
		(*i)++;
	len = get_token_len(line, *i);
	if (len == 0)
		return (NULL);
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	ft_strlcpy(token, &line[*i], len + 1);
	*i += len;
	return (token);
}

char	**tokenizer(char *line)
{
	int		count;
	char	**tokens;
	int		i;
	int		index;
	char	*token;

	count = count_tokens(line);
	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	index = 0;
	while (line[i])
	{
		token = extract_token(line, &i);
		if (token)
			tokens[index++] = token;
	}
	tokens[index] = NULL;
	return (tokens);
}

t_tokens	get_type(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return (PIPE);
	if (ft_strcmp(token, "<") == 0)
		return (INDIR);
	if (ft_strcmp(token, ">") == 0)
		return (OUTDIR);
	if (ft_strcmp(token, ">>") == 0)
		return (APPEND);
	if (ft_strcmp(token, "<<") == 0)
		return (HEREDOC);
	return (WORD);
}

char	*enum_to_str(t_tokens type)
{
	if (type == WORD)
		return ("WORD");
	if (type == PIPE)
		return ("PIPE");
	if (type == INDIR)
		return ("INDIR");
	if (type == OUTDIR)
		return ("OUTDIR");
	if (type == APPEND)
		return ("APPEND");
	if (type == HEREDOC)
		return ("HEREDOC");
	return ("UNKNOWN");
}

t_tokens	*get_array_of_types(char **tokens)
{
	int			i;
	int			count;
	t_tokens	*token_types;

	i = 0;
	count = 0;
	while (tokens[count])
		count++;
	token_types = malloc(sizeof(t_tokens) * (count + 1));
	if (!token_types)
		return (NULL);
	while (i < count)
	{
		token_types[i] = get_type(tokens[i]);
		i++;
	}
	token_types[count] = NULL_TOK;
	return (token_types);
}
