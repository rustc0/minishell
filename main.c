/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:34:40 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/17 19:40:47 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_sh(t_shell **data, char **env)
{
	*data = malloc(sizeof(t_shell));
	if (!*data)
		return ;
	(*data)->args = NULL;
	(*data)->next = NULL;
	(*data)->files = NULL;
	(*data)->line = NULL;
	glob()->exit_status = 0;
	glob()->env = init_env(env);
}
// inc_shlvl(glob()->env);

int	add_line(t_shell *data, int *i)
{
	(*i)++;
	signal(SIGINT, handle_sig);
	signal(SIGQUIT, SIG_IGN);
	if (isatty(0))
		data->line = readline("minishell:$ ");
	else
		data->line = readline("");
	signal(SIGINT, SIG_IGN);
	if (data->line && data->line[0])
		add_history(data->line);
	else if (data->line == NULL)
	{
		printf("exit\n");
		clean_env(&glob()->env);
		free(data);
		exit(glob()->exit_status);
	}
	if (ft_strcmp(data->line, "") == 0)
		return (free(data->line), free(data), 1);
	return (0);
}

void	sh_loop(t_shell *data)
{
	t_shell *(databak);
	int (i);
	i = 0;
	while (1)
	{
		if (i)
			data = malloc(sizeof(t_shell));
		databak = data;
		if (add_line(data, &i))
			continue ;
		data = parsing(data->line);
		if (data != databak)
			free(databak);
		if (!data)
			continue ;
		else if (!data->next && (data->args && ct(data->args[0]) == builtin))
		{
			if (handle_builtin(data, data->args, &(glob()->env)) == NULL)
				break ;
		}
		else
			exec_pipe(data);
		cleanup_sh(data);
	}
	cleanup_sh(data);
}

int	main(int ac, char **av, char **env)
{
	t_shell	*data;

	(void)ac;
	(void)av;
	init_sh(&data, env);
	sh_loop(data);
	clean_env(&glob()->env);
	return (glob()->exit_status);
}
