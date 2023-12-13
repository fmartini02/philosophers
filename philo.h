/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/13 15:16:46 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

enum e_status
{
	START = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	DEAD = 4
};

typedef struct s_args
{
	int				n_philo;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				deaths;
	int				x;
	long int		start;
	pthread_mutex_t *time;
	pthread_t		*thread_arr;
	pthread_mutex_t	**mutex_arr;
	pthread_mutex_t	*pick_forks_mutex;
}				t_args;

typedef struct s_philo
{
	int				id;
	int				status;
	int				special;
	long int		lap_start;
	long int		lap_current;
	long int		time_of_starv;
	long int		now;
	int				eat_num;
	t_args			*args;
}				t_philo;

typedef struct s_waiter
{
	int		**id_stat;
	int		**id_n_eat;
	t_philo	*philo;
	t_args	*args;

}			t_waiter;


void		ft_error(void);
void		ft_ferror(void);
void		ft_sleep(t_philo *args);
void		ft_eat(t_philo *args);
void		ft_think(t_philo *args);
void		*ft_routine(void *arg);
void		ft_philo(t_waiter *waiter);
int			ft_atoi(char *str);
void		ft_mutex_init(t_args *args);
void		ft_struct_init(t_args *args, t_philo *philo, t_waiter *waiter, char **av);
void		ft_special_drop_slave(int left, int right, t_philo *philo);
void		ft_special_give_slave(int left, int right, t_philo *philo);
void		ft_drop_slave(int left, int right, t_philo *philo);
void		ft_give_slave(int left, int right, t_philo *philo);
void		ft_give_mutex(int id, int tot, t_philo *philo);
void		ft_drop_mutex(int id, int tot, t_philo *philo);
long int	ft_time(char *s, t_philo *philo);
long int	ft_time2(t_philo *philo);
long int	ft_give_time(void);
int			ft_check_deadness(t_philo *philo);
void		ft_mem_free(t_args *args, t_philo *philo, t_waiter *waiter);
void		*ft_waiter_routine(void *waiter_ptr);
void		ft_init_resurce(t_args *args, t_philo *philo, t_waiter *waiter, char **av);