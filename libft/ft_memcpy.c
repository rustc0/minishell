/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:57:40 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 21:48:20 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t num)
{
	unsigned char		*to1;
	const unsigned char	*from1;

	if (!to && !from)
		return (NULL);
	to1 = (unsigned char *)to;
	from1 = (const unsigned char *)from;
	while (num--)
	{
		*to1++ = *from1++;
	}
	return ((void *)to);
}

// int main()
// {
// 	char *src;
// 	//char dest[13];

// 	src = "Hello world!";
// 	char *res = (char *)(memcpy(NULL, src, 11));

// 	printf("%s \n", res);
// }