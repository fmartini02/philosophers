/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:27 by fmartini          #+#    #+#             */
/*   Updated: 2023/11/06 18:23:40 by fmartini         ###   ########.fr       */
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
	int				sync;
	pthread_t		*thread_arr;
	pthread_mutex_t	**mutex_arr;
}				t_args;


void	ft_error(void);
void	ft_ferror(void);
void	ft_sleep(t_args *args, int i);
void	ft_eat(t_args *args, int i);
void	ft_think(t_args *args, int i);
void	*ft_iter(void *arg);
void	ft_philo(t_args *args);
int		ft_atoi(char *str);
void	ft_mutex_init(t_args *args);
void	ft_init_resurce(t_args *args, char **av);