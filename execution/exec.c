/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:50:53 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/16 21:27:44 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*run_builtin(t_shell *data, char **args, t_env **myenv)
{
	if (ft_strcmp(args[0], "echo") == 0)
		glob()->exit_status = ft_echo(args, 1);
	else if (ft_strcmp(args[0], "pwd") == 0)
		glob()->exit_status = ft_pwd();
	else if (ft_strcmp(args[0], "unset") == 0)
		glob()->exit_status = ft_unset(args + 1, myenv);
	else if (ft_strcmp(args[0], "cd") == 0)
		glob()->exit_status = ft_cd(args, get_ac(args));
	else if (ft_strcmp(args[0], "env") == 0)
		glob()->exit_status = ft_env(*myenv, get_ac(args));
	else if (ft_strcmp(args[0], "export") == 0)
		ft_export(myenv, args + 1);
	else if (ft_strcmp(args[0], "exit") == 0)
	{
		if (ft_exit(args))
			return (NULL);
	}
	else
		perror("command not found ");
	return (data);
}

void	*handle_builtin(t_shell *data, char **args, t_env **myenv)
{
	int	stdinbak;
	int	stdoutbak;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!data->args[0])
		return (*args);
	stdinbak = dup(STDIN_FILENO);
	stdoutbak = dup(STDOUT_FILENO);
	if (handle_reds(data) == -1)
	{
		dup2(stdinbak, STDIN_FILENO);
		dup2(stdoutbak, STDOUT_FILENO);
		close(stdinbak);
		close(stdoutbak);
		return (*args);
	}
	if (!run_builtin(data, args, myenv))
		return (close (stdinbak), close (stdoutbak), NULL);
	dup2(stdinbak, STDIN_FILENO);
	dup2(stdoutbak, STDOUT_FILENO);
	close (stdinbak);
	close (stdoutbak);
	return (*args);
}

int	ct(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "env") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "export") == 0)
		return (builtin);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (builtin);
	return (binary);
}

void	runbin(char *cmd, char *path, char **env, char **args)
{
	char	**dirs;
	char	*full_pth;
	int		i;

	dirs = ft_split(path, ':');
	if (!dirs || ft_strchr(cmd, '/'))
		return (free_args(dirs));
	i = 0;
	while (dirs[i])
	{
		full_pth = join_path(dirs[i], cmd);
		if (access(full_pth, X_OK) == 0)
		{
			if (execve(full_pth, args, env) == -1)
				return (free(full_pth), free_args(dirs));
		}
		free(full_pth);
		i++;
	}
	free_args(dirs);
}

int	handle_bin(t_shell *data, char *cmd, char **args)
{
	char *(path), **(envp);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (handle_reds(data) == -1)
		return (1);
	if (ft_strchr(cmd, '/') && check_if_directory(cmd))
		return (1);
	if (!cmd)
		return (1);
	envp = copyenv(glob()->env);
	if (envget(glob()->env, "PATH"))
		path = envget(glob()->env, "PATH")->value;
	else
		path = NULL;
	if (execve(cmd, args, envp) == -1 && errno == EACCES && strchr(cmd, '/'))
	{
		perror("minishell:");
		free_args(envp);
		glob()->exit_status = 126;
		return (1);
	}
	runbin(cmd, path, envp, args);
	ft_putendl_fd("minishell: command not found", 2);
	glob()->exit_status = 127;
	return (free_args(envp), 1);
}
