/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:40:52 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 22:52:59 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || num == 0)
		return (dest);
	if (d < s)
	{
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (num--)
			d[num] = s[num];
	}
	return (dest);
}

// int main ()
// {
//   char str[] = "memmove can be very useful......";
//   void *res = ft_memmove (str+20, str+15, 44);
// //   if (!res)
// // 	printf("failed\n");
// //   else
// 	printf("%s\n", str);
//   return 0;
// }
