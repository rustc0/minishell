/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:51:25 by abougati          #+#    #+#             */
/*   Updated: 2025/07/15 17:59:51 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell	*parse_all(char **tokens, t_tokens *types)
{
	int		i;

	t_shell *(head), *(curr), *(new);
	i = 0;
	head = NULL;
	curr = NULL;
	while (tokens[i] && types[i] != NULL_TOK)
	{
		new = create_new_node(tokens + i, types + i);
		if (!new)
			return (NULL);
		if (!head)
			head = new;
		else
			curr->next = new;
		curr = new;
		while (tokens[i] && types[i] != PIPE && types[i] != NULL_TOK)
			i++;
		if (types[i] == PIPE)
			i++;
	}
	return (head);
}

void	*create_new_node(char **tokens, t_tokens *types)
{
	t_shell	*new;

	new = malloc(sizeof(t_shell));
	if (!new)
		return (NULL);
	new->args = get_args(tokens, types);
	new->files = get_tfiles(tokens, types);
	new->next = NULL;
	return (new);
}

t_shell	*parsing(char *line)
{
	char		**tokens;
	t_tokens	*types;
	t_shell		*a;

	tokens = tokenizer(line);
	types = get_array_of_types(tokens);
	if (!check_syntax(line, tokens, types))
	{
		free(line);
		free_tokens(tokens);
		free(types);
		return (NULL);
	}
	free(line);
	expand_all_tokens(tokens, types);
	a = parse_all(tokens, types);
	free_tokens(tokens);
	free(types);
	return (a);
}

// change (1)
/* 
return (parse_all(tokens, types));  -->	 a = parse_all(tokens, types);
									|->	free_tokens(tokens);
									|->	free(types);
									-->	return (a);     
*/

/*
Changes :
1) drt comment 3la dok free li f parse_all() , and wllina knfreeiw 
		after parse_all return (ull see)
2) f fill_struct lowkey drt ft_strdup() l tokens w files so wlla jouj ,
		nta katms7 w7din w ana knms7 w7din f pasing()
3) f free_files -> zdt had line : free(files->files[i]); ,
		 cuz lfiles wlla tahoma duplicated 

lost track 
*/

// i tried to comment most of the changes tal lkher , nsit madrtha flwl ,
//		 so n9dr nkoun ma commentitich chi haja , well find out dik sa3

// ba9i wahd leak kaytl3 f create_node chi 9lwa , hrb lya nsit ach knt drt

// ma pushitch cuz idk wakha testif n9dr nkoun khwrt chi haja f other leaks

//  hayd anmchi nn3ss 
