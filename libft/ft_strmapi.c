/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:39:57 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/01 11:45:37 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*buff;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (NULL);
	while (i < len)
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = 0;
	return (buff);
}

// char sample_func(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'A' && c <= 'Z')
//     	return c + 32;
// 	return (c);
// }

// int main()
// {
//     char *s = "HELLO!";
//     char *result;
// 	char (*sfptr)(unsigned int, char);

// 	sfptr = sample_func;
//     result = ft_strmapi(s, sample_func);

//     printf("Original string: %s\n", s);
//     printf("Modified string: %s\n", result);

//     return 0;
// }