/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:06 by abougati          #+#    #+#             */
/*   Updated: 2025/07/13 15:13:39 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quotes(char *line)
{
	int		i;
	char	quote;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
			{
				ft_putstr_fd("minishell: syntax error: unclosed ", 2);
				if (quote == '\'')
					ft_putstr_fd("'", 2);
				else
					ft_putstr_fd("\"", 2);
				ft_putstr_fd("\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_tokens2(char **tokens, int *i)
{
	if (tokens[*i + 1])
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(tokens[*i + 1], 2);
		ft_putstr_fd("'\n", 2);
	}
	else
		ft_putstr_fd(
			"minishell: syntax error near unexpected token 'newline'\n", 2);
	return (0);
}

int	check_tokens(char **tokens, t_tokens *types)
{
	int	i;

	i = 0;
	if (types[0] == PIPE && types[1] != PIPE)
	{
		ft_putstr_fd(
			"minishell: syntax error near unexpected token `|'\n", 2);
		return (0);
	}
	while (tokens[i])
	{
		if (types[i] == PIPE && (!tokens[i + 1] || types[i + 1] == PIPE))
		{
			ft_putstr_fd(
				"minishell: syntax error near unexpected token `||'\n", 2);
			return (0);
		}
		if ((types[i] == INDIR || types[i] == OUTDIR
				|| types[i] == HEREDOC || types[i] == APPEND)
			&& (!tokens[i + 1] || types[i + 1] != WORD))
			return (check_tokens2(tokens, &i));
		i++;
	}
	return (1);
}

int	check_syntax(char *line, char **tokens, t_tokens *types)
{
	if (!check_quotes(line) || !check_tokens(tokens, types))
	{
		glob()->exit_status = 2;
		return (0);
	}
	return (1);
}
