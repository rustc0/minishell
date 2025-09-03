/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:13:13 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/17 12:58:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec(t_shell *data, t_shell *head)
{
	if (ct(data->args[0]) == builtin)
		handle_builtin(data, data->args, &(glob()->env));
	else
		handle_bin(data, data->args[0], data->args);
	cleanup_sh(head);
	clean_env(&glob()->env);
	exit (glob()->exit_status);
}

void	create_pipeline(int prevfd, t_shell *data, int *pipe_fd)
{
	if (prevfd != -1)
	{
		dup2(prevfd, STDIN_FILENO);
		close(prevfd);
	}
	if (data->next)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
}

void	wait_help(int *status, int lastpid)
{
	int (sig);
	if (waitpid(lastpid, status, 0) > 0)
	{
		if (WIFEXITED(*status))
			glob()->exit_status = WEXITSTATUS(*status);
		else if (WIFSIGNALED(*status))
		{
			sig = WTERMSIG(*status);
			if (sig == SIGINT)
			{
				printf("\n");
				glob()->exit_status = 130;
			}
			else if (sig == SIGQUIT)
			{
				printf("Quit\n");
				glob()->exit_status = 131;
			}
		}
	}
	while (1)
		if (wait(NULL) <= 0)
			break ;
}

int	help_fork(t_shell *data, int *pipe_fd, int *prevfd, t_shell *head)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit (5);
	else if (pid == 0)
	{
		create_pipeline(*prevfd, data, pipe_fd);
		exec(data, head);
	}
	return (pid);
}

void	exec_pipe(t_shell *data)
{
	int (pid), (lastpid), (status), (prevfd), (pipe_fd)[2];
	t_shell *(head);
	head = data;
	prevfd = -1;
	while (data)
	{
		if (data->next && pipe(pipe_fd) == -1)
		{
			glob()->exit_status = 129;
			return (perror("pipe"));
		}
		pid = help_fork(data, pipe_fd, &prevfd, head);
		signal(SIGINT, SIG_IGN);
		lastpid = pid;
		if (prevfd != -1)
			close(prevfd);
		if (data->next)
		{
			close(pipe_fd[1]);
			prevfd = pipe_fd[0];
		}
		data = data->next;
	}
	wait_help(&status, lastpid);
}
