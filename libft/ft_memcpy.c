/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:57:48 by fmartini          #+#    #+#             */
/*   Updated: 2022/10/27 19:08:04 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!dest && !src)
		return (0);
	ret = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ret);
}
