/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:25:54 by rahmoham          #+#    #+#             */
/*   Updated: 2025/06/13 14:59:18 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (INT_MIN);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned const char)*s1 - *s2);
}

// int main(void)
// {
// 	const char *str1 = "Hello";
// 	const char *str2 = "Hello";
// 	const char *str3 = "World";

// 	char **s = ft_split("Hello");
// 	printf("Comparing '%s' and '%s': %d\n", str1, s[0],
//  ft_strcmp(str1, s[0]));
// 	printf("Comparing '%s' and 'NULL': %d\n",
//  str1, str3, ft_strcmp(str1, NULL));

// 	return 0;
// }