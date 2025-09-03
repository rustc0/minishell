/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:43:58 by rahmoham          #+#    #+#             */
/*   Updated: 2025/05/18 10:25:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	if (size != 0 && (count > ULLONG_MAX / size))
		return (NULL);
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}

// int main()
// {
//     size_t count = 2;
//     size_t size = 9999996999999999999999999999;           

//     void *ptr = ft_calloc(count, size);
// 	if (!ptr)
// 		printf("err!\n");
// 	free(ptr);
//     return 0;
// }