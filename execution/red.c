/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:58:48 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/17 12:54:51 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cus_open(char *file, int type)
{
	int	flags;

	if (!file || !*file)
		return (-1);
	if (type == INDIR)
		flags = O_RDONLY;
	else if (type == OUTDIR)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (type == APPEND)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else if (type == HEREDOC)
		flags = O_RDONLY;
	else
		return (-1);
	return (open(file, flags, 0644));
}

int	opening_red(char **files, int *types)
{
	int (i), (fd);
	i = 0;
	if (!files)
		return (-2);
	while (files[i] && types[i] != NULL_TOK)
	{
		fd = cus_open(files[i], types[i]);
		if (fd == -1)
			return (-1);
		if (types[i] == INDIR || types[i] == HEREDOC)
		{
			if (dup2(fd, STDIN_FILENO) == -1)
				return (close(fd), -1);
		}
		if (types[i] == APPEND || types[i] == OUTDIR)
		{
			if (dup2(fd, STDOUT_FILENO) == -1)
				return (close(fd), -1);
		}
		close (fd);
		i++;
	}
	return (0);
}

int	handle_reds(t_shell *data)
{
	int (i);
	i = -3;
	if (!data || !data->files)
		return (0);
	i = opening_red(data->files->files, data->files->types);
	if (i < 0)
	{
		if (i == -2)
			return (-1);
		if (data->files->files && data->files->files[0][0] == 0)
			write(2, "minishell: ambiguous redirect\n", 31);
		else
			perror("minishell");
		glob()->exit_status = 1;
		return (-1);
	}
	return (0);
}
