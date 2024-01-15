/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/15 18:11:14 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *p)
{
	p->meals++;
	p->last_meal = timestamp_in_ms();
	p->death_timestamp = p->last_meal + p->args->die_t;
	usleep(p->args->eat_t * 1000);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000 * 3);
	while (1)
	{
		pthread_mutex_lock(philo->right_fork_p);
		pthread_mutex_lock(philo->left_fork_p);
		pthread_mutex_lock(&philo->args->print_m);
		printf("%04li %02d\e[1;35m has taken a fork\e[0m\n", timestamp_in_ms(), philo->id);
		printf("%04li %02d\e[1;35m has taken a fork\e[0m\n", timestamp_in_ms(), philo->id);
		printf("%04li %02d\e[1;32m is eating\e[0m\n", timestamp_in_ms(), philo->id);
		pthread_mutex_unlock(&philo->args->print_m);
		ft_eat(philo);
		pthread_mutex_unlock(philo->right_fork_p);
		pthread_mutex_unlock(philo->left_fork_p);
		pthread_mutex_lock(&philo->args->print_m);
		printf("%04li %02d\e[1;34m is sleeping\e[0m\n", timestamp_in_ms(), philo->id);
		pthread_mutex_unlock(&philo->args->print_m);
		usleep(philo->args->sleep_t * 1000);
		pthread_mutex_lock(&philo->args->print_m);
		printf("%04li %02d\e[1;33m is thinking\e[0m\n", timestamp_in_ms(), philo->id);
		pthread_mutex_unlock(&philo->args->print_m);
	}
	return (NULL);
}

