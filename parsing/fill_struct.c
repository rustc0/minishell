/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:21 by abougati          #+#    #+#             */
/*   Updated: 2025/07/17 19:43:00 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	char **tokens = {"<", "file.txt", ">", "output.txt", "|", "command"};
	t_tokens *types = {INDIR, WORD, OUTDIR, WORD, PIPE, WORD};
*/

char	**get_args(char **tokens, t_tokens *types)
{
	int		count;
	char	**args;
	int		i;
	int		index;

	count = count_cmdargs(tokens, types);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	i = 0;
	index = 0;
	while (tokens[i] && types[i] != PIPE && types[i] != NULL_TOK)
	{
		if (types[i] == WORD && (i == 0 || (types[i - 1] != INDIR
					&& types[i - 1] != OUTDIR && types[i - 1] != HEREDOC
					&& types[i - 1] != APPEND)))
			args[index++] = ft_strdup(tokens[i]);
		i++;
	}
	args[index] = NULL;
	return (args);
}

void	get_files(t_files *files, char **tokens, t_tokens *types)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (tokens[i] && types[i] != PIPE && types[i] != NULL_TOK)
	{
		if (types[i] == INDIR || types[i] == OUTDIR || types[i] == APPEND)
		{
			if (tokens[i + 1] == NULL)
			{
				files->files[index] = NULL;
				files->types[index] = NULL_TOK;
				return ;
			}
			files->files[index] = ft_strdup(tokens[i + 1]);
			files->types[index] = types[i];
			index++;
		}
		else if (types[i] == HEREDOC && check_hdoc(files, tokens, &index, &i))
			return ;
		i++;
	}
	files->files[index] = NULL;
	files->types[index] = NULL_TOK;
}

int	check_hdoc(t_files *files, char **tokens, int *index, int *i)
{
	char	*heredoc_path;
	char	*delim;

	heredoc_path = NULL;
	delim = ft_strdup(tokens[*i + 1]);
	if (tokens[(*i) + 1] == NULL
		|| handle_herdoc(delim, &heredoc_path))
	{
		free(delim);
		free(files->files);
		files->files = NULL;
		files->types[(*index)] = NULL_TOK;
		return (1);
	}
	free(delim);
	files->files[(*index)] = heredoc_path;
	files->types[(*index)] = HEREDOC;
	(*index)++;
	return (0);
}

t_files	*get_tfiles(char **tokens, t_tokens *types)
{
	int		i;
	t_files	*files;

	i = count_files(tokens, types);
	files = malloc(sizeof(t_files));
	if (!files)
		return (NULL);
	if (i == 0)
	{
		free(files);
		return (NULL);
	}
	files->files = malloc(sizeof(char *) * (i + 1));
	files->types = malloc(sizeof(t_tokens) * (i + 1));
	if (!files->files || !files->types)
	{
		free(files->files);
		free(files->types);
		free(files);
		return (NULL);
	}
	get_files(files, tokens, types);
	return (files);
}
