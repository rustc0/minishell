/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:16:01 by abougati          #+#    #+#             */
/*   Updated: 2025/07/13 15:27:57 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_name(char *str)
{
	int	len;

	len = 0;
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	return (ft_substr(str, 0, len));
}

char	*get_env_value(char *key, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

char	*append_str(char *dst, char *src)
{
	char	*tmp;

	tmp = ft_strjoin(dst, src);
	free(dst);
	return (tmp);
}

char	*append_char(char *dst, char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = 0;
	return (append_str(dst, buf));
}

int	is_valid_1st_char_var(char c)
{
	return (ft_isalpha(c) || c == '_');
}
