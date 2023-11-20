/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:38:30 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/20 17:28:41 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_give_time()
{
	struct timeval	time;
	long int		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

long int ft_time(char *s, t_philo *philo)
{
    long int		now;
	long int		res;
	static long int	last;

	pthread_mutex_lock(philo->args->time);
    if (*s == '\0')
	{
		last = ft_give_time();
		res = 0;
	}
	else 
	{
		now = ft_give_time();
		res = now - last;
		last = now;
	}
	pthread_mutex_unlock(philo->args->time);
	return (res);
}
