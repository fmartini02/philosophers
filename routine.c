/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2024/02/07 17:12:14 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_forks(t_philo *p)
{
	pthread_mutex_lock(p->right_fork_p);
	ft_print("has taken right fork\n", p->id, p);
	pthread_mutex_lock(p->left_fork_p);
	ft_print("has taken left fork\n", p->id, p);
}

void	ft_eat(t_philo *p)
{
	ft_lock_forks(p);
	pthread_mutex_lock(&p->args->dstamp_m);
	p->meals++;
	p->last_meal = timestamp_in_ms();
	p->death_timestamp = p->last_meal + p->args->die_t;
	pthread_mutex_unlock(&p->args->dstamp_m);
	ft_print("is eating\n",p->id, p);
	usleep(p->args->eat_t * 1000);
	pthread_mutex_unlock(p->right_fork_p);
	pthread_mutex_unlock(p->left_fork_p);
}

int	ft_check_death(t_philo *p)
{
	int	r;

	r = 0;
	pthread_mutex_lock(&p->args->checker_m);
	if (p->args->end == 1)
		r++;
	pthread_mutex_unlock(&p->args->checker_m);
	return (r);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(3000);
	if (philo->id == philo->args->n_philos)
		usleep(1000);
	while (ft_check_death(philo) == 0)
	{
		ft_print("before eat\n", philo->id, philo);
		ft_eat(philo);
		ft_print("after eat\n", philo->id, philo);
		ft_print("is sleeping\n", philo->id, philo);
		usleep(philo->args->sleep_t * 1000);
		ft_print("is thinking\n", philo->id, philo);
	}
	return (NULL);
}

