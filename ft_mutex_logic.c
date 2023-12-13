/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:18 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/13 15:35:09 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_mutex(t_philo *philo, int left, int right)
{
	int ret;

	ret = 0;
	if(!philo->args->mutex_arr[left] || !philo->args->mutex_arr[right - 1])
	{
		ret = 1;
		usleep(philo->args->die_t * 1000);
	}
	return (ret);
}

void	ft_give_mutex(int id, int tot, t_philo *philo)
{
	if(id == 1 && tot == 1)
	{
		if (ft_check_mutex(philo, id, tot))
		{
			printf("timestamp:%ld %d took a fork\n",ft_time2(philo), id);
			return ;
		}
	}
    if(id - 1 == 0)
		ft_special_give_slave(tot - 1, id - 1, philo);	
    else
		ft_give_slave(id - 2, id - 1, philo);
}

void	ft_drop_mutex(int id, int tot, t_philo *philo)
{
	if(id == 1 && tot == 1)
	{
		if (ft_check_mutex(philo, id, tot))
			return ;
	}
	if(id - 1 == 0)
	{
		ft_special_drop_slave(tot - 1, id - 1, philo);
		philo->special++;
	}
	else
		ft_drop_slave(id - 2, id - 1, philo);
}

void	*ft_waiter_routine(void *waiter_ptr)
{
	int	i;
	int iter;
	int	n_philo;
	t_waiter *waiter;

	i = 0;
	waiter = (t_waiter *)waiter_ptr;
	iter = 1;
	n_philo = waiter->args->n_philo;
	while (iter)
	{
		while (i < n_philo)
		{
			if (waiter->philo[i].status == DEAD)
			{
				printf("timestamp:%ld %d died\n",ft_time2(waiter->philo), i + 1);
				waiter->args->deaths = 1;
				iter = 0;
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}
