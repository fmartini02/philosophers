/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/06 18:36:27 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	
	if (ac < 5 || ac > 6)
		ft_error();
	args = malloc(sizeof(t_args));
	if (args == NULL)
		ft_ferror();
	ft_init_resurce(args, av);
	if (args->x < 1 
		|| args->die_t < args->eat_t + args->sleep_t 
		|| args->eat_t < 0 
		|| args->sleep_t < 0 
		|| args->die_t < 0)
		ft_error();
	else
		ft_philo(args);
}
