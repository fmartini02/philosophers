/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:41:41 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/13 15:54:11 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_give_slave(int left, int right, t_philo *philo)
{
	int id;
	long int timestamp;

	id = philo->id;
	timestamp = ft_time2(philo);
	if (id % 2 == 0)
	{
		pthread_mutex_lock(philo->args->mutex_arr[right]);
		printf("timestamp:%ld %d took right fork\n", timestamp, id);
		pthread_mutex_lock(philo->args->mutex_arr[left]);
		printf("timestamp:%ld %d took left fork\n\n", timestamp, id);
	}
	else
	{
		pthread_mutex_lock(philo->args->mutex_arr[left]);
		printf("timestamp:%ld %d took left fork\n", timestamp, id);
		pthread_mutex_lock(philo->args->mutex_arr[right]);
		printf("timestamp:%ld %d took right fork\n\n", timestamp, id);
	}
}
void	ft_drop_slave(int left, int right, t_philo *philo)
{
	int id;
	long int timestamp;

	id = philo->id;
	timestamp = ft_time2(philo);
	if (id % 2 == 0)
	{
		pthread_mutex_unlock(philo->args->mutex_arr[left]);
		printf("timestamp:%ld %d droped left fork\n", timestamp, id);
		pthread_mutex_unlock(philo->args->mutex_arr[right]);
		printf("timestamp:%ld %d droped right fork\n\n", timestamp, id);
	}
	else
	{
		pthread_mutex_unlock(philo->args->mutex_arr[right]);
		printf("timestamp:%ld %d droped right fork\n", timestamp, id);
		pthread_mutex_unlock(philo->args->mutex_arr[left]);
		printf("timestamp:%ld %d droped left fork\n\n", timestamp, id);
	}
}