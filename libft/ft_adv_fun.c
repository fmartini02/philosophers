/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:10:33 by fmartini          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:57 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_point(unsigned long schiff, char str, int *n)
{
	unsigned long	nb;

	nb = schiff;
	if (nb >= 16)
	{
		ft_put_point(nb / 16, str, n);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (str == 'p')
			ft_putchar("0123456789abcdef"[nb], n);
	}
	return (nb);
}

void	ft_point(unsigned long schif, int *n, char str)
{
	if (schif)
	{
		ft_putstr("0x", n);
		ft_put_point(schif, str, n);
	}
	else
		ft_putstr("(nil)", n);
}
