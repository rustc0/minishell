/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:09:59 by rahmoham          #+#    #+#             */
/*   Updated: 2025/07/03 15:32:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) != NULL)
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
	{
		write(2, "pwd: error retrieving current directory\n", 41);
		return (1);
	}
}
