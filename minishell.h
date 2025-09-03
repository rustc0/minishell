/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:28:39 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/17 19:41:20 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_env		t_env;
typedef struct s_shell		t_shell;
typedef unsigned long long	t_ull;

typedef enum e_type
{
	builtin,
	binary,
}	t_type;

typedef struct s_env
{
	char	*key;
	char	*value;
	t_env	*next;
	t_env	*prev;
}	t_env;

typedef struct s_global
{
	t_env	*env;
	int		exit_status;
}	t_global;

typedef enum e_tokens
{
	WORD, // cmd, args, file_names
	PIPE, // |
	INDIR, // <
	OUTDIR, // >
	APPEND, // >>
	HEREDOC, // <<
	NULL_TOK, // works like NULL
}	t_tokens;

typedef struct s_files
{
	char	**files;
	int		*types;
}	t_files;

typedef struct s_shell
{
	char	*line;
	char	**args;
	t_files	*files;
	t_shell	*next;
}	t_shell;

# define BLUE "\033[34m"
# define RED "\033[31m"
# define PURPLE "\001\033[0;35m\002"
# define GREEN "\033[32m"
# define RESET "\033[0m"

// builtins funcs

int			ft_echo(char **args, int fd);
int			ft_pwd(void);
int			ft_cd(char **args, int ac);
int			ft_env(t_env *env, int ac);
int			ft_unset(char **keys, t_env **env);
void		ft_export(t_env **env, char **args);
int			ft_exit(char **args);
void		noargs_export(t_env *env);

// env/helper funcs

t_env		*init_env(char **env);
t_env		*envget(t_env *env, char *key);
t_env		*newenv(char *env, int hid);
void		add_envnode(t_env **head, t_env *new);
t_env		*sort_env(t_env *env);
void		clean_env(t_env **head);
int			get_ac(char **args);
void		cleanup_sh(t_shell *data);
t_ull		ft_atoull(char *str);
int			check_if_directory(char *path);
char		*join_path(char *dir, char *cmd);

// exec funcs

t_global	*glob(void);
void		*handle_builtin(t_shell *data, char **args, t_env **myenv);
void		*run_builtin(t_shell *data, char **args, t_env **myenv);
int			handle_bin(t_shell *data, char *cmd, char **args);
int			ct(char *cmd);
char		**copyenv(t_env *envlist);
void		inc_shlvl(t_env *env);
void		free_args(char **args);

// pipe funcs

void		exec_pipe(t_shell *data);
int			handle_reds(t_shell *data);
void		handle_sig(int sig);

// parsing stuff

char		**tokenizer(char *line);
int			get_token_len(char *line, int i);
char		*extract_token(char *line, int *i);
char		*enum_to_str(t_tokens type);

t_tokens	get_type(char *token);
t_tokens	*get_array_of_types(char **tokens);
int			count_tokens(char *line);
int			is_seperator(char c);
int			is_special(char c);

char		**get_args(char **tokens, t_tokens *types);
void		print_args(char **args);

t_files		*get_tfiles(char **tokens, t_tokens *types);
void		get_files(t_files *files, char **tokens, t_tokens *types);
void		print_files(t_files *files);

void		free_tokens(char **tokens);
void		free_files(t_files *files);
void		free_list(t_shell *head);

t_shell		*parse_all(char **tokens, t_tokens *types);
void		*create_new_node(char **tokens, t_tokens *types);
t_shell		*parsing(char *line);

int			count_cmdargs(char **tokens, t_tokens *types);
int			count_files(char **tokens, t_tokens *types);

int			check_syntax(char *line, char **tokens, t_tokens *types);

int			handle_herdoc(char *eof, char **file_path);
int			check_hdoc(t_files *files, char **tokens, int *index, int *i);

void		expand_all_tokens(char **tokens, t_tokens *types);
char		*expand_variables(char *input);
char		*get_var_name(char *str);
char		*get_env_value(char *key, t_env *env);
char		*append_str(char *dst, char *src);
char		*append_char(char *dst, char c);
int			is_valid_1st_char_var(char c);

void		handle_dollar(char *input, int *i, char **result);
void		handle_digit_var(char *input, int *i, char **result, char *var1);
void		handle_named_var(char *input, int *i, char **result);

int			is_quoted(char *eof);
char		*expand_line(char *input);
char		*fix_eof(char *input);

#endif