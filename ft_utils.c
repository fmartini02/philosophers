/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:15 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/16 17:46:04 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	printf("Error:\nwrong arguments\n");
	exit(0);
}

void	ft_ferror(void)
{
	printf("Error:\nfunction failed\n");
	exit(0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		nmb *= 10;
		nmb += (*str - '0');
		str++;
	}
	return (nmb *= sign);
}

void	ft_mutex_init(t_args *args)
{
	int	t;
	int	i;

	t = args->x;
	i = 0;
	args->mutex_arr = malloc(t * sizeof(pthread_mutex_t*));
	if (args->mutex_arr == NULL)
		ft_ferror();
	t--;
	while(i <= t)
	{
		args->mutex_arr[i] = malloc(sizeof(pthread_mutex_t));
		if (args->mutex_arr[i] == NULL)
			ft_ferror();
		pthread_mutex_init(args->mutex_arr[i], NULL);
		i++;
	}
}

void	ft_init_resurce(t_args *args, t_philo *philo, t_waiter *waiter, char **av)
{
	int	t;

	args->x = ft_atoi(av[1]);
	t = args->x;
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->n_philo = t;
	args->deaths = 0;
	ft_struct_init(args, philo, waiter);
	args->thread_arr = malloc(sizeof(pthread_t) * args->x);
	if (args->thread_arr == NULL)
		ft_ferror();
	ft_mutex_init(args);
}
