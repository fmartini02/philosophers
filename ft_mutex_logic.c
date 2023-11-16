/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:18 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/16 17:49:45 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_waiter(t_philo *philo)
{
	philo->waiter->id_stat[philo->id - 1][1] = 1;/*1 = eating*/
	if(philo->id == philo->args->n_philo)
	{
		pthread_mutex_lock(philo->args->mutex_arr[0]);
    	pthread_mutex_lock(philo->args->mutex_arr[philo->id-1]);
	}
    else if(philo->id - 1 == 0)
    {
		pthread_mutex_lock(philo->args->mutex_arr[philo->id-1]);
		pthread_mutex_lock(philo->args->mutex_arr[philo->args->n_philo - 1]);
	}
    else
    {
		pthread_mutex_lock(philo->args->mutex_arr[philo->id-1]);
		pthread_mutex_lock(philo->args->mutex_arr[philo->id]);
	}
}

void	ft_unlock(t_philo *philo)
{
	philo->waiter->id_stat[philo->id - 1][1] = 2;/*2 = sleeping*/
	//printf("%d\n", philo->waiter->id_stat[philo->id - 1][1]);
	if(philo->id == philo->args->n_philo)
	{
		pthread_mutex_unlock(philo->args->mutex_arr[0]);
		pthread_mutex_unlock(philo->args->mutex_arr[philo->id - 1]);
	}
	else if(philo->id - 1 == 0)
	{
		pthread_mutex_unlock(philo->args->mutex_arr[philo->id - 1]);
		pthread_mutex_unlock(philo->args->mutex_arr[philo->args->n_philo - 1]);
	}
	else
	{
		pthread_mutex_unlock(philo->args->mutex_arr[philo->id - 1]);
		pthread_mutex_unlock(philo->args->mutex_arr[philo->id]);
	}
}
