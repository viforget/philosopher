/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:34:21 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:04:02 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_ph *ph)
{
	free(ph->tm_lst_eat);
	free(ph);
}

void	alloc_2(pthread_mutex_t **m, int **meal, pthread_t **th, t_info info)
{
	*m = malloc(sizeof(pthread_mutex_t) * info.nb_philo);
	*meal = malloc(sizeof(int) * info.nb_philo);
	*th = malloc(sizeof(pthread_t) * info.nb_philo);
}

void	free2(pthread_mutex_t *mutex, int *meal, pthread_t *th, t_ph **ph)
{
	free(mutex);
	free(meal);
	free(th);
	free(ph);
}

t_ph	*fully_ph(t_info info, pthread_mutex_t *m, pthread_mutex_t *st, int *ml)
{
	t_ph			*ph;
	unsigned long	*a;
	int				j;
	static int		i = 0;

	j = 0;
	while (j < info.nb_philo)
		meal[j++] = 0;
	a = malloc(sizeof(unsigned long));
	ph = malloc(sizeof(t_ph));
	ph->index = i++;
	ph->info = info;
	ph->tm_lst_eat = a;
	ph->mutex = m;
	ph->talking_stick = st;
	ph->meal = ml;
	return (ph);
}
