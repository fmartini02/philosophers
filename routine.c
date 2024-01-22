/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/22 18:30:03 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->args->checker_m);
	p->meals++;
	p->last_meal = timestamp_in_ms();
	p->death_timestamp = p->last_meal + p->args->die_t;
	pthread_mutex_unlock(&p->args->checker_m);
	usleep(p->args->eat_t * 1000);
	pthread_mutex_unlock(p->right_fork_p);
	pthread_mutex_unlock(p->left_fork_p);
}

void	ft_pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_p);
	pthread_mutex_lock(philo->left_fork_p);
	ft_print("has taken a fork\n",philo->id, philo);
	ft_print("has taken a fork\n",philo->id, philo);
	ft_print("is eating\n",philo->id, philo);
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
		ft_pick_forks(philo);
		ft_eat(philo);
		ft_print("is sleeping\n", philo->id, philo);
		usleep(philo->args->sleep_t * 1000);
		ft_print("is thinking\n", philo->id, philo);
	}
	return (NULL);
}

