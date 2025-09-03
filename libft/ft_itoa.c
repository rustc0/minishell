/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:18:26 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/11 17:15:57 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buff;
	long	num;

	num = n;
	len = get_len(num);
	buff = (char *)malloc(len * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	buff[len] = 0;
	if (num == 0)
		buff[0] = '0';
	if (num < 0)
	{
		buff[0] = '-';
		num = -num;
	}
	while (num)
	{
		buff[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (buff);
}

// int main()
// {
//     int num = 2147483647;
//     char *str = ft_itoa(num);
//     if (str) 
//		{
//         printf("The number as a string: %s\n", str);
//         free(str); 
//		}
//     return 0;
// }