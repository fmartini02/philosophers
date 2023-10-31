/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:04:56 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/21 15:57:39 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_class(char str, va_list l, int *n)
{
	if (str == 'c')
		ft_putchar(va_arg(l, int), n);
	else if (str == 's')
		ft_putstr(va_arg(l, char *), n);
	else if (str == 'i' || str == 'd')
		ft_putnbr(va_arg(l, int), n);
	else if (str == 'p')
		ft_point((unsigned long)va_arg(l, void *), n, str);
	else if (str == 'x' || str == 'X')
		ft_print_hex(va_arg(l, unsigned int), str, n);
	else if (str == 'u')
		ft_putnbr_s(va_arg(l, unsigned int), n);
	else if (str == '%')
		ft_putchar('%', n);
	else
	{
		ft_putchar('%', n);
		ft_putchar(str, n);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	l;
	int		n;

	n = 0;
	va_start(l, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str, &n);
			str++;
		}
		else
		{
			if (!*(str + 1))
			{
				va_end(l);
				return (-1);
			}
			ft_check_class(str[1], l, &n);
			str += 2;
		}
	}
	va_end(l);
	return (n);
}
/*
# include <stdio.h>

int	main(void)
{
	char	*s;

	s = 0;
	printf("\t%d\n", printf("a"));
	ft_printf("\t%d", ft_printf("a"));
	printf("\t%d\n", printf("%c", 46));
	ft_printf("\t%d\n", ft_printf("%c", 46));
	printf("\t%d\n", printf("%c", 0));
	ft_printf("\t%d\n", ft_printf("%c", 0));
	printf("\t%d\n", printf("%c", 128));
	ft_printf("\t%d\n", ft_printf("%c", 128));
	printf("\t%d\n", printf("%s", "ciao"));
	ft_printf("\t%d\n", ft_printf("%s", "ciao"));
	printf("\t%d\n", printf("%s", s));
	ft_printf("\t%d\n", ft_printf("%s", s));
	ft_printf("\n");
	printf("\t%d", printf("%p", &s));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", &s));
	ft_printf("\n");
	printf("\t%d", printf("%p", (void *)s));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", (void *)s));
	ft_printf("\n");
	printf("\t%d", printf("%p", (void *)234));
	printf("\n");
	ft_printf("\t%d", ft_printf("%p", (void *)234));
	ft_printf("\n");
	printf("\t%d", printf("%d", 0));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", 0));
	ft_printf("\n");
	printf("\t%d", printf("%d", 2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", 2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%d", -2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%d", -2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%i", 2147483647));
	printf("\n");
	ft_printf("\t%d", ft_printf("%i", 2147483647));
	ft_printf("\n");
	printf("\t%d", printf("%u", -1));
	printf("\n");
	ft_printf("\t%d", ft_printf("%u", -1));
	ft_printf("\n");
	printf("\t%d", printf("%u", -9));
	printf("\n");
	ft_printf("\t%d", ft_printf("%u", -9));
	ft_printf("\n");
	printf("\t%d", printf("%x", 104683));
	printf("\n");
	ft_printf("\t%d", ft_printf("%x", 104683));
	ft_printf("\n");
	printf("\t%d", printf("%X", 962354));
	printf("\n");
	ft_printf("\t%d", ft_printf("%X", 962354));
	ft_printf("\n");
	printf("\t%d", printf("abcd '%d%%'", 37));
	printf("\n");
	ft_printf("\t%d", ft_printf("abcd '%d%%'", 37));
	ft_printf("\n");
	return (0);
}*/
