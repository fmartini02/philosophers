/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:26:55 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/21 15:57:03 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int c, int *n)
{
	write(1, &c, 1);
	*n += 1;
}

void	ft_putstr(char *str, int *n)
{
	int		i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			ft_putchar(str[i], n);
			i++;
		}
	}
	else
		ft_putstr("(null)", n);
}

void	ft_putnbr(int nb, int *n)
{
	long	nbr;

	nbr = nb;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", n);
		return ;
	}
	if (nbr < 0)
	{
		nbr = (nbr * -1);
		ft_putchar('-', n);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, n);
		ft_putchar((nbr % 10) + '0', n);
	}
	else
		ft_putchar(nbr + '0', n);
}

void	ft_putnbr_s(unsigned int nbr, int *n)
{
	unsigned long	nb;

	nb = nbr;
	if (nb >= 10)
	{
		ft_putnbr_s(nb / 10, n);
		nb = nb % 10;
	}
	ft_putchar(nb + '0', n);
}
