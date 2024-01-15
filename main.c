/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/18 16:54:26 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_threads(t_args *args)
{
	int	i;
	int	fail;

	i = 0;
	while (i < args->n_philos)
	{
		fail = pthread_create(args->thread_arr + i, NULL, &ft_routine, (args->philo) + i);
		if (fail)
			return (0);
		i++;
	}
	return (1);
}
static int	stop_threads(t_args *args)
{
	int	i;
	int	fail;

	i = 0;
	while (i < args->n_philos)
	{
		fail = pthread_detach(args->thread_arr[i]);
		if (fail)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_args	*args;

	if (ac < 5 || ac > 6)
	{
		printf("wrong arguments\n");
		printf("arguments must be: num_philo, die_time, eat_time, sleep_time and eat_number(optional)\n");
		return (1);
	}
	args = ft_init_resurce(av);
	if (!args)
		return (1);
	if (args->n_philos == 1)
	{
		ft_one_philo(args->philo, 0, 1);
		return (0);
	}
	if (!create_threads(args))
		return (2);
	wait_for_completion(args);
	if (!stop_threads(args))
		return (3);
	usleep(10000);
	ft_free_mem(args);
	return (0);
}
