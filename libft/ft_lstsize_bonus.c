/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:01 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/06 13:09:07 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		len;

	curr = lst;
	len = 0;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}
