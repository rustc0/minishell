/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:17:44 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 21:32:36 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t num)
{
	const unsigned char	*p;
	unsigned char		ch;

	p = (const unsigned char *)ptr;
	ch = (unsigned char)c;
	while (num--)
	{
		if (*p == ch)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// int main(void)
// {
//   char *pch;
//   char str[] = "Example string";
//   pch = (char*) ft_memchr (str, 'p', ft_strlen(str));
//   if (pch!=NULL)
//     printf ("'p' found at position %ld.\n", pch-str+1);
//   else
//     printf ("'p' not found.\n");
// }
