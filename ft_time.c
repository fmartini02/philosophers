/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:38:30 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/16 18:11:40 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_give_time()
{
	struct timeval	time;
	int				ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int	ft_get_time()
{
	static	int		last = 0;
	long int		now;

	if (last == 0)
	{
		printf("first time = %d\n", last);
		last = ft_give_time();
	}
	else
	{
		now = ft_give_time();
		printf("time = %ld\n", now - last);
		last = now;
	}
	printf("last = %d\n", last);
	return (last);
}
