/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:27:04 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/19 14:57:03 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dest && i < size)
	{
		++dest;
		++i;
	}
	ret = ft_strlcpy(dest, src, size - i);
	return (ret + i);
}
