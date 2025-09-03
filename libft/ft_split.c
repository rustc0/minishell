/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:28:43 by rahmoham          #+#    #+#             */
/*   Updated: 2025/06/10 13:10:00 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cw(char *str, char d)
{
	size_t	count;
	int		in;

	count = 0;
	in = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != d && !in)
		{
			count++;
			in = 1;
		}
		else if (*str == d)
		{
			in = 0;
		}
		str++;
	}
	return (count);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	*ft_clean(char **arr, int allocated)
{
	int	j;

	j = 0;
	while (j < allocated)
		free (arr[j++]);
	free (arr);
	return (NULL);
}

char	**ft_split(char *str, char d)
{
	char	**arr;

	int (i), (j), (k);
	i = 0;
	k = 0;
	if (!str || !cw(str, d))
		return (NULL);
	arr = malloc(sizeof(char *) * (cw(str, d) + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == d))
			i++;
		j = i;
		while (str[i] && (str[i] != d))
			i++;
		if (i > j)
		{
			arr[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!arr[k])
				return (ft_clean(arr, k), NULL);
			ft_strncpy(arr[k++], &str[j], i - j);
		}
	}
	arr[k] = NULL;
	return (arr);
}

// int main()
// {
// 	char s[] = "   hello, ,this,is a test,n0   ,";
// 	char **ret = ft_split(s, ' ');

// 	for (size_t i = 0; ret[i] != NULL; i++)
// 	{
// 		printf("%s\n", ret[i]);
// 	}

// 	free(ret);

// 	return 0;
// }