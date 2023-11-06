/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:54 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/06 18:28:33 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_args *args, int i)
{
	long elapsed_ms;
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	usleep(1000);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
	if(elapsed_ms >= args->die_t)
	{
		printf("nphilosopher number: %d is now dead\n",i);
		args->deaths = 1;
		exit(0);
	}
	printf("time to think: %ld \nphilosopher number: %d is now eating\n", elapsed_ms, i);
}

void	ft_sleep(t_args *args, int i)
{
	long elapsed_ms;
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	usleep(args->sleep_t * 1000);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
	if(elapsed_ms >= args->die_t)
	{
		printf("nphilosopher number: %d is now dead\n", i);
		args->deaths = 1;
		exit(0);
	}
	printf("time to sleep: %ld \nphilosopher number: %d is now thinking\n", elapsed_ms, i);
}

void	ft_eat(t_args *args, int i)
{
	long elapsed_ms;
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	pthread_mutex_lock(args->mutex_arr[i]);
	pthread_mutex_lock(args->mutex_arr[args->n_philo - 1]);
	usleep(args->eat_t * 1000);
	gettimeofday(&end, NULL);
	pthread_mutex_unlock(args->mutex_arr[i]);
	pthread_mutex_unlock(args->mutex_arr[args->n_philo - 1]);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
	if(elapsed_ms >= args->die_t)
	{
		printf("philosopher number: %d is now dead\n", i);
		args->deaths = 1;
		exit(0);
	}
	printf("time to eat: %ld \nphilosopher number: %d is now sleeping\n", elapsed_ms, i);
}

void	*ft_iter(void *arg)
{
	int	i;
	t_args *args;
	
	args = (t_args *)arg;
	i = args->n_philo - args->x;
	args->x--;
	while(args->sync == 0)
	  	//printf("waiting for syncrhonization...\n");
	while(args->deaths == 0)
	{
		ft_eat(args, i);
		ft_sleep(args, i);
		ft_think(args, i);
	}
	return (NULL);
}

void	ft_philo(t_args *args )
{
	int	i;

	i = 1;
	while(i <= (args->n_philo))
	{
		//printf("args pointer is : %p\n", args);
		pthread_create(&args->thread_arr[i - 1], NULL, ft_iter, args);
		printf("\t%d\n", i);
		i += 2;
	}
	i = 2;
	args->sync = 1;
	while(i <= args->n_philo)
	{
		//printf("args pointer is : %p\n", args);
		pthread_create(&args->thread_arr[i - 1], NULL, ft_iter, args);
		printf("\t%d\n", i);
		i += 2;
	}
	i = 0;
	while(i < args->n_philo)
	{
		pthread_join(args->thread_arr[i], NULL);
		i++;
	}
}