/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/16 18:08:05 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args		*args;
	t_philo		*philo;
	t_waiter	*waiter;
	
	if (ac < 5 || ac > 6)
		ft_error();
	philo = malloc(sizeof(t_philo) * (ft_atoi(av[1])));
	if (philo == NULL)
		ft_ferror();
	waiter = malloc(sizeof(t_waiter));
	if (waiter == NULL)
		ft_ferror();
	args = malloc(sizeof(t_args));
	if (args == NULL)
		ft_ferror();
	ft_init_resurce(args, philo, waiter, av);
	if (args->x < 1 
		|| args->die_t < args->eat_t + args->sleep_t 
		|| args->eat_t < 0 
		|| args->sleep_t < 0 
		|| args->die_t < 0)
		ft_error();
	else
		ft_philo(philo);
}
