/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:27 by fmartini          #+#    #+#             */
/*   Updated: 2024/01/17 16:06:59 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdint.h>
#include "libft/libft.h"

typedef struct s_philo
{
	struct s_args	*args;
	int				id;
	pthread_mutex_t	*right_fork_p;
	pthread_mutex_t	*left_fork_p;
	int				last_meal;
	int				meals;
	int				death_timestamp;
}				t_philo;

typedef struct s_args
{
	pthread_t		*thread_arr;
	pthread_mutex_t	checker_m;
	pthread_mutex_t	print_m;
	pthread_mutex_t	*mutex_arr;
	int				n_philos;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				times_to_eat;
	int				end;
	t_philo			*philo;
}				t_args;



void		ft_eat(t_philo *args);
void		*ft_routine(void *arg);
void		ft_ferror(void);
void		ft_one_philo(t_philo *philos, int left_fork, int id);
void		wait_for_completion(t_args *args);
int			ft_atoi(char *str);
void		ft_mutex_init(t_args *args);
void		ft_struct_init(t_args *args, t_philo *philo);
uint64_t	timestamp_in_ms(void);
uint64_t	gettimeofday_ms(void);
void		ft_free_mem(t_args *args);
void		ft_drop_forks(t_philo *philo, int id);
t_args		*ft_init_resurce(char **av);