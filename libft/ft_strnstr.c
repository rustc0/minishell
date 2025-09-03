/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:18:47 by rahmoham          #+#    #+#             */
/*   Updated: 2024/10/27 23:41:09 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	nlen = ft_strlen(ndl);
	if (!*ndl)
		return ((char *)hs);
	while (hs[i] && nlen + i <= len)
	{
		if (ft_strncmp(hs + i, ndl, nlen) == 0)
			return ((char *)(hs + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	const char *haystack = "Hello world";
// 	const char *needle = "world";

// 	char *result = strnstr((void *)0, "fake", 3);

// 	printf("res: %s\n", result);

// 	return 0;
// }