/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/31 16:10:21 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

typedef struct s_args
{
	int				n_philo;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				deaths;
	int				x;
	int				sync;
	pthread_t		*thread_arr;
	pthread_mutex_t	**mutex_arr;
}				t_args;

void	ft_error(void)
{
	printf("Error:\nwrong arguments\n");
	exit(0);
}

void	ft_ferror(void)
{
	printf("Error:\nfunction failed\n");
	exit(0);
}

void	ft_mutex_int(t_args *args)
{
	int	t;

	t = args->x;
	args->mutex_arr = malloc(t * sizeof(pthread_mutex_t*));
	if (args->mutex_arr == NULL)
		ft_ferror();
	t--;
	while(t >= 0)
	{
		args->mutex_arr[t] = malloc(sizeof(pthread_mutex_t));
		if (args->mutex_arr[t] == NULL)
			ft_ferror();
		pthread_mutex_init(args->mutex_arr[t], NULL);
		t--;
	}
}

void	ft_init_resurce(t_args *args, char **av)
{
	int	t;

	args->x = ft_atoi(av[1]);
	t = args->x;
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->n_philo = 0;
	args->deaths = 0;
	args->sync = 0;
	args->thread_arr = malloc(sizeof(pthread_t) * args->x);
	if (args->thread_arr == NULL)
		ft_ferror();
	ft_mutex_int(args);
}

void	ft_think(t_args *args, int i)
{
	long elapsed_ms;
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	usleep(1);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1e6;
	elapsed_ms += (end.tv_usec - start.tv_usec);
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
	usleep(args->sleep_t);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1e6;
	elapsed_ms += (end.tv_usec - start.tv_usec);
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
	pthread_mutex_lock(args->mutex_arr[args->n_philo]);
	usleep(args->eat_t);
	pthread_mutex_unlock(args->mutex_arr[i]);
	pthread_mutex_unlock(args->mutex_arr[args->n_philo]);
	gettimeofday(&end, NULL);
	elapsed_ms = (end.tv_sec - start.tv_sec) * 1e6;
	elapsed_ms += (end.tv_usec - start.tv_usec);
	if(elapsed_ms >= args->die_t)
	{
		printf("nphilosopher number: %d is now dead\n", i);
		args->deaths = 1;
		exit(0);
	}
	printf("time to eat: %ld \nphilosopher number: %d is now sleeping\n", elapsed_ms, i);
}

void	*ft_iter(void *arg)
{
	int	i;
	struct timeval start, end;
	long elapsed_ms;
	t_args *args;
	
	args = (t_args *)arg;
	i = args->n_philo - args->x;
	args->x--;
	while(args->sync == 0)
		printf("waiting for syncrhonization...\n");
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
	while(i <= args->x)
	{
		pthread_create(&args->thread_arr[i - 1], NULL, ft_iter, args);
		i += 2;
	}
	i = 2;
	args->sync = 1;
	while(i <= args->x)
	{
		printf("%ld\n", args->thread_arr[i-1]);
		pthread_create(&args->thread_arr[i - 1], NULL, ft_iter, args);
		i += 2;
		printf("%ld\n", args->thread_arr[i-1]);
	}
	i = 0;
	while(i <= args->x)
	{
		pthread_join(args->thread_arr[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_args	*args;
	
	args = malloc(sizeof(t_args));
	if (args == NULL)
		ft_ferror();
	ft_init_resurce(args, av);
	if (args->x < 1 
		|| args->die_t < args->eat_t + args->sleep_t 
		|| args->eat_t < 0 
		|| args->sleep_t < 0 
		|| args->die_t < 0)
		ft_error();
	else
		ft_philo(args);
}
