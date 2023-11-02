/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:47 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/02 18:16:53 by fmartini         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	sign;
	int	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		nmb *= 10;
		nmb += (*str - '0');
		str++;
	}
	return (nmb *= sign);
}

void	ft_mutex_int(t_args *args)
{
	int	t;
	int	i;

	t = args->x;
	i = 0;
	args->mutex_arr = malloc(t * sizeof(pthread_mutex_t*));
	if (args->mutex_arr == NULL)
		ft_ferror();
	t--;
	while(i <= t)
	{
		args->mutex_arr[i] = malloc(sizeof(pthread_mutex_t));
		if (args->mutex_arr[i] == NULL)
			ft_ferror();
		pthread_mutex_init(args->mutex_arr[i], NULL);
		i++;
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
	args->n_philo = t;
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
	struct timeval start, end;
	long elapsed_ms;
	t_args *args;
	
	args = (t_args *)arg;
	i = args->n_philo - args->x;
	args->x--;
	// while(args->sync == 0)
	// 	printf("waiting for syncrhonization...\n");
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
		pthread_create(&args->thread_arr[i - 1], NULL, ft_iter, args);
		i += 2;
	}
	i = 0;
	while(i <= args->n_philo)
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
