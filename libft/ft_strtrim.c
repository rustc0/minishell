/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:27:06 by rahmoham          #+#    #+#             */
/*   Updated: 2024/10/29 13:10:00 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*buff;
	int		nsize;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(&s1[ft_strlen(s1)]));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	nsize = end - start + 2;
	buff = (char *)malloc(nsize);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1 + start, nsize);
	return (buff);
}

// int main(void)
// {
// 	char str[] = "@#@#!!#!@@##!";
// 	char s[] = "!@#";

// 	printf("before : %s\n", str);
// 	char *s2 = ft_strtrim(str, s);
// 	printf("after : %s\n", s2);

// 	return 0;
// }