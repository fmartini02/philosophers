/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/20 17:28:51 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	pthread_mutex_t *time;
	pthread_t		*thread_arr;
	pthread_mutex_t	**mutex_arr;
}				t_args;

typedef struct s_waiter
{
	int	**id_stat;
	int	**mut_stat;
	int	**id_n_eat;

}			t_waiter;

typedef struct s_philo
{
	int				id;
	t_args			*args;
	t_waiter		*waiter;
}				t_philo;

void		ft_error(void);
void		ft_ferror(void);
void		ft_sleep(t_philo *args);
void		ft_eat(t_philo *args);
void		ft_think(t_philo *args);
void		*ft_routine(void *arg);
void		ft_philo(t_philo *philo);
int			ft_atoi(char *str);
void		ft_mutex_init(t_args *args);
void		ft_struct_init(t_args *args, t_philo *philo, t_waiter *waiter);
void		ft_waiter(t_philo *philo);
long int	ft_time(char *s, t_philo *philo);
void		ft_unlock(t_philo *philo);
void		ft_init_resurce(t_args *args, t_philo *philo, t_waiter *waiter, char **av);