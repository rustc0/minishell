/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:15 by rahmoham          #+#    #+#             */
/*   Updated: 2024/10/27 23:40:54 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = (size_t)ft_strlen(src);
	if (dstsize == 0)
		return (ret);
	while (*src && dstsize - 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (ret);
}

// int main() {
//     char src[] = "Hello, world!";
//     char dst[10];

//     size_t res = ft_strlcpy(dst, src, sizeof(dst));

//     printf("Destination: %s\n return: %zu\n", dst, res);  
//     return 0;
// }