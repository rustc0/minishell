/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:11:19 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/11 21:27:07 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(char **args, int fd)
{
	int (i), (newline), (j);
	i = 1;
	newline = 1;
	while (args[i] && (ft_strncmp(args[i], "-n", 2) == 0))
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1])
			write(fd, " ", 1);
		i++;
	}
	if (newline)
		write(fd, "\n", 1);
	return (0);
}
