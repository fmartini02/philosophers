/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/20 17:30:11 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	long elapsed_ms;

	philo->waiter->id_stat[philo->id - 1][1] = 3;/*3 = thinking*/
	usleep(1000);
	elapsed_ms = ft_time("t", philo);
	if(elapsed_ms >= philo->args->die_t)
	{
		printf("nphilosopher number: %d is now dead\n", philo->id);
		philo->args->deaths = 1;
		exit(0);
	}
	printf("time to think: %ld \nphilosopher number: %d is now eating\n", elapsed_ms, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	long elapsed_ms;
	
	usleep(philo->args->sleep_t * 1000);
	elapsed_ms = ft_time("s", philo);
	if(elapsed_ms >= philo->args->die_t)
	{
		printf("nphilosopher number: %d is now dead\n", philo->id);
		philo->args->deaths = 1;
		exit(0);
	}
	printf("time to sleep: %ld \nphilosopher number: %d is now thinking\n", elapsed_ms, philo->id);
}

void	ft_eat(t_philo *philo)
{
    long	elapsed_ms;
    
	ft_waiter(philo);
    usleep(philo->args->eat_t * 1000);
	ft_unlock(philo);
    elapsed_ms = ft_time("e", philo);
    if(elapsed_ms >= philo->args->die_t)
    {
        printf("philosopher number: %d is now dead\n", philo->id);
        philo->args->deaths = 1;
        exit(0);
    }
    printf("time to eat: %ld \nphilosopher number: %d is now sleeping\n", elapsed_ms, philo->id);
}

void	*ft_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		usleep(philo->args->eat_t * 1000);
	while(philo->args->deaths == 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_philo(t_philo *philo)
{
	int			j;
	long int	t;

	j = 0;
	t = ft_time("", philo);
	t++;
	while(j <= philo->args->n_philo - 1)
	{
		pthread_create(&philo->args->thread_arr[j], NULL, ft_routine, &philo[j]);
		printf("%d\n", j+1);
		j++;
	}
	j = 0;
	while(j < philo->args->n_philo - 1)
	{
		pthread_join(philo->args->thread_arr[j], NULL);
		j++;
	}
}
