/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:51:52 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/12 16:51:33 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_waiter_init(t_waiter *waiter, t_args *args, t_philo *philo)
{
	int	i;
	int	t;

	i = 0;
	t = args->n_philo;
	waiter->philo = philo;
	waiter->args = args;
	while (i < t)
	{
		waiter->id_stat[i] = malloc(sizeof(int) * 2);
		if (waiter->id_stat[i] == NULL)
			ft_ferror();
		waiter->id_n_eat[i] = malloc(sizeof(int) * 2);
		if (waiter->id_n_eat[i] == NULL)
			ft_ferror();
		waiter->id_stat[i][0] = i;
		waiter->id_n_eat[i][0] = i;
		waiter->id_stat[i][1] = 0;
		waiter->id_n_eat[i][1] = 0;
		i++;
	}
}

void	ft_struct_init(t_args *args, t_philo *philo, t_waiter *waiter, char **av)
{
	int	i;
	int	t;

	i = 0;
	t = args->n_philo;
	while (i < t)
	{
		philo[i].id = i + 1;
		philo[i].args = args;
		philo[i].now = 0;
		philo[i].special = 0;
		philo[i].lap_start = 0;
		philo[i].lap_current = 0;
		philo[i].status = START;
		philo[i].time_of_starv = 0;
		if(av[5])
			philo[i].eat_num = ft_atoi(av[5]);
		else
			philo[i].eat_num = -1;
		i++;
	}
	waiter->id_stat = malloc(sizeof(int *) * t);
	if(waiter->id_stat == NULL)
		ft_ferror();
	waiter->id_n_eat = malloc(sizeof(int *) * t);
	if (waiter->id_n_eat == NULL)
		ft_ferror();
	ft_waiter_init(waiter, args, philo);
}
