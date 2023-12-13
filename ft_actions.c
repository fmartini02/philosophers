/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/13 16:04:46 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	int		id;
	long	timestamp;

	if (ft_check_deadness(philo))
		return ;
	id = philo->id;
	timestamp = ft_time2(philo);
	philo->status = THINKING;
	philo->lap_current = ft_give_time();
	if (ft_check_deadness(philo))
		return ;
	printf("timestamp:%ld %d is now eating\n\n",timestamp, id);/*inizia a mangiare*/
}

void	ft_sleep(t_philo *philo)
{
	long timestamp;
	int id;

	if (ft_check_deadness(philo))
		return ;
	id = philo->id;
	philo->status = SLEEPING;
	usleep(philo->args->sleep_t * 1000);
	timestamp = ft_time2(philo);
	philo->lap_current = ft_give_time();
	philo->time_of_starv = philo->lap_current - philo->lap_start;
	if (ft_check_deadness(philo))
		return;
	printf("timestamp:%ld %d is now thinking\n\n",timestamp, id);
}

void	ft_eat(t_philo *philo)
{
	long	timestamp;
	int		id;
	int		tot;

	id = philo->id;
	tot = philo->args->n_philo;
	if (ft_check_deadness(philo))
		return;       
	philo->lap_start = ft_give_time();/*per calcolare se il tempo di mangiata è più grande di die_t*/
	ft_give_mutex(id, tot, philo);/*per dare le forchette*/
	philo->status = EATING;/*per dire al waiter che sta mangiando*/
	usleep(philo->args->eat_t * 1000);/*tempo per mangiare*/
	ft_drop_mutex(id, tot, philo);/*per lasciare le forchette*/
	timestamp = ft_time2(philo);/*per dare il timestamp*/
	philo->lap_current = ft_give_time();/*per calcolare il tempo passato dall`inizio della mangiata*/
	if (ft_check_deadness(philo))/*per controllare se è morto*/
		return;
	philo->lap_start = ft_give_time();/*per risettare il lap*/
	printf("timestamp:%ld %d is now sleeping\n\n",timestamp, id);
}

void	*ft_routine(void *philo_ptr)
{
	t_philo	*philo;
	int		eat_count;
	int		eat_num;

	philo = (t_philo *)philo_ptr;
	eat_count = 0;
	eat_num = philo->eat_num;
	if (eat_num < 0)/*nel caso non ci sia quante volte mangiare*/
	{
		eat_count = -2147483647;
		eat_num = 2147483647;
	}
	if (philo->id % 2 == 0)
		usleep(3000);
	while(philo->args->deaths == 0 && eat_count < eat_num)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		eat_count++;
	}
	return (NULL);
}

void	ft_philo(t_waiter *waiter)
{
	int	i;
	int	n_philo;

	i = 1;
	n_philo = waiter->args->n_philo;
	waiter->args->start = ft_give_time();
	pthread_create(&waiter->args->thread_arr[0], NULL, ft_waiter_routine, waiter);
	while(i <= n_philo)
	{
		pthread_create(&waiter->args->thread_arr[i], NULL, ft_routine, &waiter->philo[i-1]);
		//printf("philo %d created\n", i + 1);
		i++;
	}
	i = 0;
	while(i < n_philo + 1)
	{
		pthread_join(waiter->args->thread_arr[i], NULL);
		i++;
	}
	ft_mem_free(waiter->args, waiter->philo, waiter);
}
