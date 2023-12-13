/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:38:30 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/13 15:19:45 by fmartini         ###   ########.fr       */
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

long int ft_time2(t_philo *philo)
{
	long int		res;

	res = ft_give_time() - philo->args->start;
	return (res);
}

int ft_check_deadness(t_philo *philo)
{
	int res;

	res = 0;
	if (philo->status == START)
		return (res);
	if (philo->lap_current == 0)
		philo->time_of_starv = philo->lap_start - philo->args->start;
	philo->time_of_starv = philo->lap_current - philo->lap_start;
	if (philo->time_of_starv >= philo->args->die_t)
	{
		//printf("starvation time:%ld\n", philo->time_of_starv);
		philo->status = DEAD;
		res = 1;
	}
	return (res);
}