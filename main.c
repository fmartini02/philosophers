/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/22 17:57:07 by fmartini         ###   ########.fr       */
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

void ft_wrong_arguments(void)
{
	printf("wrong arguments\n");
	printf("usage: ./philosophers n_philos die_t eat_t sleep_t [times_to_eat]\n");
	exit(1);
}

void	ft_print(char *str, int id, t_philo *p)
{
	pthread_mutex_lock(&p->args->checker_m);
	if (p->args->end == 1)
	{
		pthread_mutex_unlock(&p->args->checker_m);
		return ;
	}
	pthread_mutex_unlock(&p->args->checker_m);
	pthread_mutex_lock(&p->args->print_m);
	printf("timestamp:%li [%d] %s", timestamp_in_ms(), id, str);
	pthread_mutex_unlock(&p->args->print_m);
}

int	main(int ac, char **av)
{
	t_args	*args;
	int		i;

	i = 0;
	if (ac < 5 || ac > 6)
		ft_wrong_arguments();
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
	while(i < args->n_philos)
	{
		pthread_join(args->thread_arr[i], NULL);
		i++;
	}
	usleep(10000);
	ft_free_mem(args);
	return (0);
}
