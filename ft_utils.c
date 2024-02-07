/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:15 by fmartini          #+#    #+#             */
/*   Updated: 2024/02/07 16:38:40 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_ferror(void)
{
	printf("heap allocation failed\n");
	exit(1);
}

long int	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

long int	timestamp_in_ms(void)
{
	static long int	start = 0;

	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
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

void ft_free_mem(t_args *args)
{
	pthread_mutex_destroy(&args->print_m);
	pthread_mutex_destroy(&args->checker_m);
	pthread_mutex_destroy(&args->dstamp_m);
	while (args->n_philos--)
		pthread_mutex_destroy(&args->mutex_arr[args->n_philos]);
	free(args->philo);
	free(args->mutex_arr);
	free(args->thread_arr);
	free(args);
}
