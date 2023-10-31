/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:36:46 by lcasu             #+#    #+#             */
/*   Updated: 2023/06/19 15:06:18 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "libft.h"

int	ft_strlen_gnl(char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	res = malloc(lens1 + lens2 + 1);
	i = 0;
	while (i < lens1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < lens2)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	while (s[i] && !res)
	{
		if (s[i] == c)
			res = &((char *)s)[i];
		i++;
	}
	return (res);
}

char	*ft_strdup_gnl(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i])
		i++;
	res = malloc(i + 1);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_calloc_gnl(size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			((char *)res)[i] = 0;
			i++;
		}
	}
	return (res);
}
