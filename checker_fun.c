/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:18 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/15 18:12:48 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_philo *philos, int left_fork, int id)
{
	pthread_mutex_lock(&philos->args->mutex_arr[left_fork]);
	printf("timestamp:%ld %d has taken a fork\n",timestamp_in_ms(), id);
	usleep(philos->args->die_t * 1000);
	printf("timestamp:%ld %d died\n",timestamp_in_ms(), id);
	pthread_mutex_unlock(&philos->args->mutex_arr[left_fork]);
	free(philos->args->mutex_arr);
	free(philos->args->thread_arr);
	free(philos->args);
	free(philos);
	return;
}

void ft_drop_forks(t_philo *philo, int id)
{
	int left_fork = id;
	int right_fork = (id + 1) % philo->args->n_philos;

	if(philo->args->n_philos == 1)
		return;
	pthread_mutex_unlock(&philo->args->mutex_arr[left_fork]);
//	printf("timestamp:%ld %d has droped a fork\n",timestamp_in_ms(), id);
	pthread_mutex_unlock(&philo->args->mutex_arr[right_fork]);
//	printf("timestamp:%ld %d has droped a fork\n",timestamp_in_ms(), id);
}
int	ft_every_full(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philos)
	{
		if ((args->philo + i)->meals >= args->times_to_eat)
			return (1);
		i++;
	}
	return (0);
}
void	wait_for_completion(t_args *args)
{
	int deaths;
	int	limit;
	int	timestamp;
	int	i;

	i = 0;
	deaths = 0;
	while (!deaths && !ft_every_full(args))
	{
		i = 0;
		while (i < args->n_philos)
		{
			limit = (args->philo + i)->death_timestamp;
			timestamp = timestamp_in_ms();
			if (limit + 10 < timestamp)
				printf("%04i %02d\033[0;35m died\033[0m\n", timestamp - 10, i);
			i++;
		}
	}
}
