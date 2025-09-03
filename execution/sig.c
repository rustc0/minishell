/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:34:39 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/15 17:11:22 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sig(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	glob()->exit_status = 130;
}

// other non related functions cuz of normz

void	cleanup_sh(t_shell *data)
{
	t_shell	*tmp;
	t_shell	*next;

	tmp = data;
	while (tmp)
	{
		next = tmp->next;
		free_tokens(tmp->args);
		free_files(tmp->files);
		free(tmp);
		tmp = next;
	}
}

char	*join_path(char *dir, char *cmd)
{
	char	*full;

	int (len1), (len2), (i), (j);
	len1 = ft_strlen(dir);
	len2 = ft_strlen(cmd);
	i = 0;
	full = malloc(len1 + len2 + 2);
	if (!full)
		return (NULL);
	while (i < len1)
	{
		full[i] = dir[i];
		i++;
	}
	full[i++] = '/';
	j = 0;
	while (j < len2)
		full[i++] = cmd[j++];
	full[i] = 0;
	return (full);
}

int	check_if_directory(char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (0);
	if ((st.st_mode & __S_IFMT) == __S_IFDIR)
	{
		ft_putendl_fd("minishell: Is a directory", 2);
		glob()->exit_status = 126;
		return (1);
	}
	return (0);
}
