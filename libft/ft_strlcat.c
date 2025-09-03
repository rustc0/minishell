/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:56:18 by rahmoham          #+#    #+#             */
/*   Updated: 2025/06/01 21:24:12 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	slen;
	size_t	l;
	size_t	i;

	slen = ft_strlen(src);
	l = 0;
	i = 0;
	while (dest[l] && l < size)
		l++;
	if (size == 0 || size <= l)
		return (slen + size);
	while (src[i] && i < (size - l - 1))
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (l + slen);
}

// int main() {
//     char dest[] = "Hello, ";
//     const char *src = "World!";

//     size_t result = strlcat(dest, src, sizeof(dest));

//     printf("Resulting string: %s\n", dest);
//     printf("Total length of concatenated string: %zu\n", result);

//     return 0;
// }
