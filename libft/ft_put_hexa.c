/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:56:58 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/23 17:54:13 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char str, int *n)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, str, n);
		ft_put_hex(num % 16, str, n);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'), n);
		else
		{
			if (str == 'x')
				ft_putchar((num - 10 + 'a'), n);
			if (str == 'X')
				ft_putchar((num - 10 + 'A'), n);
		}
	}
}

int	ft_print_hex(unsigned int num, const char str, int *n)
{
	if (num == 0)
		ft_putchar('0', n);
	else
		ft_put_hex(num, str, n);
	return (ft_hex_len(num));
}
