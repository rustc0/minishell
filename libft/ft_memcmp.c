/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:49 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 21:34:24 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)ptr;
	p2 = (const unsigned char *)ptr2;
	while (num--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// int main(void)
// {
// 	char str1[] = "Hello";
// 	char str2[] = "Help, World!";
// 	int result = ft_memcmp(str1, str2, 4);

// 	printf("%d\n", result);
// }