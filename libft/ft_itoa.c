/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:34:37 by fmartini          #+#    #+#             */
/*   Updated: 2022/10/12 15:59:28 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	j;
	long	i;
	long	nb;

	i = 0;
	nb = n;
	j = ft_numlen(n);
	str = malloc ((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		i++;
		nb = -nb;
	}
	str[j--] = '\0';
	while (j >= i)
	{
		str[j--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
