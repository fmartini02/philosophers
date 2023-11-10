/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:51:52 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/10 17:57:26 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_waiter_init(t_waiter *waiter, t_args *args)
{
	int	i;
	int	t;

	i = 0;
	t = args->n_philo;
	while (i < t)
	{
		waiter->id_stat[i] = malloc(sizeof(int) * 2);
		if (waiter->id_stat[i] == NULL)
			ft_ferror();
		waiter->mut_stat[i] = malloc(sizeof(int) * 2);
		if (waiter->mut_stat[i] == NULL)
			ft_ferror();
		waiter->id_n_eat[i] = malloc(sizeof(int) * 2);
		if (waiter->id_n_eat[i] == NULL)
			ft_ferror();
		waiter->id_stat[i][0] = i;
		waiter->mut_stat[i][0] = i;
		waiter->id_n_eat[i][0] = i;
		waiter->id_stat[i][1] = 0;
		waiter->mut_stat[i][1] = 0;
		waiter->id_n_eat[i][1] = 0;
		i++;
	}
}

void	ft_struct_init(t_args *args, t_philo *philo, t_waiter *waiter)
{
	int	i;
	int	t;

	i = 0;
	t = args->n_philo;
	while (philo[i].id < t)
	{
		philo[i].id = i;
		philo[i].args = args;
		philo[i].waiter = waiter;
		i++;
	}
	waiter->id_stat = malloc(sizeof(int *) * t);
	if(waiter->id_stat == NULL)
		ft_ferror();
	waiter->mut_stat = malloc(sizeof(int *) * t);
	if (waiter->mut_stat == NULL)
		ft_ferror();
	waiter->id_n_eat = malloc(sizeof(int *) * t);
	if (waiter->id_n_eat == NULL)
		ft_ferror();
	ft_waiter_init(waiter, args);
}
