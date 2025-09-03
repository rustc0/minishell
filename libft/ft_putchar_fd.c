/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:52:52 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/10 22:53:33 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (fd < 0)
		return ;
	write(fd, &ch, 1);
}

// int main()
// {
// 	char c = 'o';
// 	ft_putchar_fd(c, 1);
// }