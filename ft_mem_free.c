/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <fmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:39:34 by fmartini          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:25 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mem_free(t_args *args, t_philo *philo, t_waiter *waiter)
{
    int i;
    int t;

    i = 0;
    t = args->n_philo;
   while (i < t)
   {
        free(waiter->id_stat[i]);
        waiter->id_stat[i] = NULL;
        free(waiter->id_n_eat[i]);
        waiter->id_n_eat[i] = NULL;
        free(args->mutex_arr[i]);
        args->mutex_arr[i] = NULL;
        i++;
    }
    i = 0;
    if (args->mutex_arr != NULL)
    {
        while (i < t)
        {
            if (args->mutex_arr[i] != NULL)
            {
                pthread_mutex_destroy(args->mutex_arr[i]);
                free(args->mutex_arr[i]);
            }
            i++;
        }
        free (args->mutex_arr);
        args->mutex_arr = NULL;
    }
    pthread_mutex_destroy(args->time);
    pthread_mutex_destroy(args->pick_forks_mutex);
    free(philo);
    free(waiter);
    free(args->mutex_arr);
    free(args->thread_arr);
    free(args);
}
