/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/10 17:50:28 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	long elapsed_ms;
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	usleep(1000);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
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
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	usleep(philo->args->sleep_t * 1000);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
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
    long elapsed_ms;
    struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);
    usleep(philo->args->eat_t * 1000);
    gettimeofday(&end, NULL);
    elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    if(elapsed_ms >= philo->args->die_t)
    {
        printf("philosopher number: %d is now dead\n", philo->id);
        philo->args->deaths = 1;
        exit(0);
    }
    printf("time to eat: %ld \nphilosopher number: %d is now sleeping\n", elapsed_ms, philo->id);
}

void	*ft_iter(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
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
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(i <= philo->args->n_philo)
	{
		pthread_create(&philo->args->thread_arr[i - 1], NULL, ft_iter, &philo[j]);
		printf("\t%d\n", i);
		i++;
		j++;
	}
	i = 0;
	while(i < philo->args->n_philo)
	{
		pthread_join(philo->args->thread_arr[i], NULL);
		i++;
	}
}
