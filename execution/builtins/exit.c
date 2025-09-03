/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:11:06 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/02 12:07:18 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_dig(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **args)
{
	printf("exit\n");
	if (args[1] && (!is_dig(args[1]) || ft_atoull(args[1]) == ULLONG_MAX))
	{
		ft_putendl_fd("exit: numeric argument required\n", 2);
		glob()->exit_status = 2;
		return (1);
	}
	if (args[1] && args[2])
	{
		ft_putendl_fd("exit: too many arguments\n", 2);
		glob()->exit_status = 1;
		return (0);
	}
	if (ft_atoi(args[1]))
		glob()->exit_status = ft_atoi(args[1]);
	return (1);
}
