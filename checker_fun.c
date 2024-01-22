/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:18 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/22 18:32:17 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_philo *p, int left_fork, int id)
{
	pthread_mutex_lock(&p->args->mutex_arr[left_fork]);
	ft_print("has taken a fork\n", id, p);
	usleep(p->args->die_t * 1000);
	ft_print("died\n", id, p);
	pthread_mutex_unlock(&p->args->mutex_arr[left_fork]);
	free(p->args->mutex_arr);
	free(p->args->thread_arr);
	free(p->args);
	free(p);
	return;
}

int	ft_every_full(t_args *args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (args->times_to_eat == -1)
		return (0);
	while (i < args->n_philos)
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
int	ft_dead(t_args *args, int i, int deaths)
{
	ft_print("died\n", i, args->philo + i);
	deaths++;
	pthread_mutex_lock(&args->checker_m);
	args->end = 1;
	pthread_mutex_unlock(&args->checker_m);
	return (deaths);
}
void	ft_full(t_args *args)
{
	ft_print("All philosophers have eaten enough\n", 0, args->philo);
	pthread_mutex_lock(&args->checker_m);
	args->end = 1;
	pthread_mutex_unlock(&args->checker_m);
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
				deaths = ft_dead(args, i, deaths);
				break;
			}
			i++;
		}
	}
	if (!deaths)
		ft_full(args);
}
