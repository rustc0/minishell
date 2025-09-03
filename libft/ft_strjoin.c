/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:52:16 by rahmoham          #+#    #+#             */
/*   Updated: 2024/10/26 22:50:22 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*buff;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buff = (char *)(malloc(s1len + s2len + 1));
	if (!buff)
		return (NULL);
	ft_strcpy(buff, s1);
	ft_strcpy(buff + s1len, s2);
	return (buff);
}

// int main()
// {
// 	char *s = "hello ";
// 	char *s2 = "world!";

// 	char *arr = ft_strjoin(s, s2);

// 	printf("%s\n", arr);
// }