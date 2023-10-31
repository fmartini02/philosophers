/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:37:00 by fmartini          #+#    #+#             */
/*   Updated: 2022/10/06 19:43:46 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*pt;

	pt = (const char *) s;
	while (n--)
	{
		if (*pt == (char) c)
			return ((void *)pt);
		pt++;
	}
	return (0);
}
