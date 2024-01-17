/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:18 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/17 16:37:42 by fmartini         ###   ########.fr       */
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

int	ft_every_full(t_args *args)
{
	int	i;
	int	n_p;
	int	res;

	i = 0;
	res = 0;
	n_p = args->n_philos;
	if (args->times_to_eat == -1)
		return (0);
	while (i < n_p)
	{
		pthread_mutex_lock(&args->checker_m);
		if (args->philo[i].meals >= args->times_to_eat)
		{
			res++;
			i++;
		}
		else
		{
			res = 0;
			pthread_mutex_unlock(&args->checker_m);
			break;
		}
		pthread_mutex_unlock(&args->checker_m);
	}
	return (res);
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
			if (limit < timestamp)
			{
				pthread_mutex_lock(&args->print_m);
				printf("%04i %02d\033[0;35m died\033[0m\n", timestamp, i);
				pthread_mutex_unlock(&args->print_m);
				deaths++;
				pthread_mutex_lock(&args->checker_m);
				args->end = 1;
				pthread_mutex_unlock(&args->checker_m);
				break;
			}
			i++;
		}
	}
	if (!deaths)
	{
		pthread_mutex_lock(&args->print_m);
		printf("All philos ate %d times\n", args->times_to_eat);
		pthread_mutex_unlock(&args->print_m);
		args->end = 1;
	}
}
