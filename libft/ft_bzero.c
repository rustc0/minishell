/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:20:58 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 19:06:45 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n--)
	{
		*p++ = 0;
	}
}

// int main()
// {
// 	int i = 900;
// 	char c = 'a';
// 	int *ptr = &i;
// 	bzero((void *)ptr, 1);
// 	// ft_bzero((void *)(&c), 1);
// 	printf("==> %d\n", i);
// }