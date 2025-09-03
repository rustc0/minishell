/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:04:42 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/06 13:08:18 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t num)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	while (num--)
	{
		*d++ = (unsigned char)value;
	}
	return (dest);
}

// int main(void)
// {
//     char str[] = "ghghghghghghghghghghgh";
//     printf("%s\n", str);
//     ft_memset(&str[9],1400,10);
//     printf("%s", str);
// }