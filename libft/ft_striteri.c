/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:18:44 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/01 11:45:11 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (i < (int)ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}

// void print_char_with_index(unsigned int index, char *c)
// {
//     printf("%u : %c\n", index, *c);
// }

// int main()
// {
//     char str[] = "Hello, World!";

//     ft_striteri(str, print_char_with_index);

//     return 0;
// }