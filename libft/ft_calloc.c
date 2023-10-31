/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:22:45 by fmartini          #+#    #+#             */
/*   Updated: 2022/10/27 19:08:41 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*arr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	i = nmemb * size;
	arr = malloc(i);
	if (!arr)
		return (0);
	else
	{
		ft_bzero(arr, i);
	}
	return (arr);
}
