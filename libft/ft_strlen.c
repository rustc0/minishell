/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:31:59 by rahmoham          #+#    #+#             */
/*   Updated: 2025/06/10 13:20:39 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// int	main()
// {
// 	char *str;

// 	str = "hello		 ho!";
// 	size_t res = ft_strlen(str);
// 	size_t res2 = strlen(str);

// 	printf("%zu \n%zu \n", res, res2);
// }