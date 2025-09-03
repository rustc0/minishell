/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:58:57 by rahmoham          #+#    #+#             */
/*   Updated: 2024/10/28 16:31:25 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (NULL);
	if (len > 0)
		ft_strlcpy(buff, s + start, len + 1);
	else
		buff[0] = 0;
	return (buff);
}

// int main(void)
// {
// 	char s[] = "Hello, world!";
// 	char *str;
// 	size_t	size = 10;

// 	str = ft_substr("", 7, 6);

// 	printf("substring is : %s\n", str);
// }