/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:51:52 by fmartini          #+#    #+#             */
/*   Updated: 2024/02/19 18:29:57 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_init(t_args *args)
{
	int	n_philos;
	int	i;

	n_philos = args->n_philos;
	i = 0;
	args->mutex_arr = malloc(sizeof(pthread_mutex_t) * (n_philos));
	if (args->mutex_arr == NULL)
		ft_ferror();
	while (i < n_philos)
	{
		pthread_mutex_init(&args->mutex_arr[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->print_m, NULL);
	pthread_mutex_init(&args->checker_m, NULL);
	pthread_mutex_init(&args->dstamp_m, NULL);
}

void	ft_struct_init(t_args *args, t_philo *philo)
{
	int	i;
	int	t;

	i = 0;
	t = args->n_philos;
	while (i < t)
	{
		philo[i].id = i + 1;
		philo[i].args = args;
		philo[i].last_meal = 0;
		philo[i].meals = 0;
		philo[i].death_timestamp = args->die_t;
		philo[i].right_fork_p = &args->mutex_arr[i];
		if (i == 0)
			philo[i].left_fork_p = &args->mutex_arr[t - 1];
		else
			philo[i].left_fork_p = &args->mutex_arr[i - 1];
		i++;
	}
}

t_args	*ft_init_resurce(char **av)
{
	t_args	*args;
	t_philo	*philo;

	args = malloc(sizeof(t_args));
	args->thread_arr = malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	philo = malloc(sizeof(t_philo) * (ft_atoi(av[1])));
	if (args == NULL || args->thread_arr == NULL || philo == NULL)
		ft_ferror();
	args->philo = philo;
	args->n_philos = ft_atoi(av[1]);
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->end = 0;
	if (av[5])
		args->times_to_eat = ft_atoi(av[5]);
	else
		args->times_to_eat = -1;
	ft_mutex_init(args);
	ft_struct_init(args, philo);
	return (args);
}
