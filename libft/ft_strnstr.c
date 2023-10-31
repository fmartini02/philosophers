/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:41:39 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/19 14:59:43 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	b = (char *) big;
	i = 0;
	if (little[i] == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] && (i + j) < len)
		{
			if (b[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == 0)
			return (&b[i]);
		i++;
	}
	return (0);
}
