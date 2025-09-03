/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:21:12 by ayoub             #+#    #+#             */
/*   Updated: 2025/07/17 11:34:53 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_all_tokens(char **tokens, t_tokens *types)
{
	int		i;
	char	*expanded;

	i = 0;
	while (tokens[i])
	{
		if (types[i] == WORD)
		{
			if (i > 0 && types[i - 1] == HEREDOC)
			{
				i++;
				continue ;
			}
			expanded = expand_variables(tokens[i]);
			free(tokens[i]);
			tokens[i] = expanded;
		}
		i++;
	}
}

void	handle_digit_var(char *input, int *i, char **result, char *var1)
{
	char	*value;

	var1[0] = input[*i + 1];
	var1[1] = 0;
	value = get_env_value(var1, glob()->env);
	if (value)
		*result = append_str(*result, value);
	else
		*result = append_str(*result, "");
	*i += 2;
}

void	handle_named_var(char *input, int *i, char **result)
{
	char	*var2;
	char	*value;

	var2 = get_var_name(&input[*i + 1]);
	value = get_env_value(var2, glob()->env);
	if (value)
	{
		*result = append_str(*result, value);
		free(value);
	}
	else
		*result = append_str(*result, "");
	*i += ft_strlen(var2) + 1;
	free(var2);
}

void	handle_dollar(char *input, int *i, char **result)
{
	char	var1[2];
	char	*tmp;

	if (input[*i + 1] == '?')
	{
		tmp = ft_itoa(glob()->exit_status);
		*result = append_str(*result, tmp);
		free (tmp);
		*i += 2;
	}
	else if ((input[*i + 1] == '"' && input[*i + 2] == '"' )
		|| (input[*i + 1] == '\'' && input[*i + 2] == '\''))
		(*i)++;
	else if (input[*i + 1] == '"' && input[*i + 2] != '"'
		&& (input[*i + 2] || input[*i + 2] == '$'))
		(*i)++;
	else if (ft_isdigit(input[*i + 1]))
		handle_digit_var(input, i, result, var1);
	else if (is_valid_1st_char_var(input[*i + 1]))
		handle_named_var(input, i, result);
	else
		*result = append_char(*result, input[(*i)++]);
}

char	*expand_variables(char *input)
{
	char	*result;
	int		i;
	int		in_single;
	int		in_double;

	result = ft_calloc(1, 1);
	i = 0;
	in_single = 0;
	in_double = 0;
	while (input[i])
	{
		if ((input[i] == '\'' && !in_double) || (input[i] == '"' && !in_single))
		{
			if (input[i] == '\'' && !in_double)
				in_single = !in_single;
			else if (input[i] == '"' && !in_single)
				in_double = !in_double;
			i++;
		}
		else if (input[i] == '$' && in_single == 0)
			handle_dollar(input, &i, &result);
		else
			result = append_char(result, input[i++]);
	}
	return (result);
}
