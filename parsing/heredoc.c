/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:30 by abougati          #+#    #+#             */
/*   Updated: 2025/07/17 13:01:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_heredoc_input(int fd, char *eof, char *copy_eof)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, eof) == 0)
		{
			if (!line)
				printf("heredoc delimited by end-of-file (wanted `%s')\n", eof);
			break ;
		}
		if (!is_quoted(copy_eof))
			line = expand_line(line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
}

void	handle_heredoc_child(char *eof, char *copy_eof, char *file_path)
{
	int	fd;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		exit(1);
	process_heredoc_input(fd, eof, copy_eof);
	close(fd);
	free(eof);
	free(copy_eof);
	clean_env(&(glob()->env));
	exit(0);
}

int	handle_herdoc(char *eof, char **file_path)
{
	int		pid;
	int		stat;
	char	*copy_eof;
	char	*fixed_eof;

	copy_eof = eof;
	fixed_eof = fix_eof(eof);
	*file_path = "/tmp/.hdocfile";
	pid = fork();
	if (pid == 0)
		handle_heredoc_child(fixed_eof, copy_eof, *file_path);
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		wait(&stat);
		free(fixed_eof);
		if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGINT)
		{
			printf("\n");
			glob()->exit_status = 130;
			return (1);
		}
	}
	return (0);
}
