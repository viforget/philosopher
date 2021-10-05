/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:34:23 by viforget          #+#    #+#             */
/*   Updated: 2021/10/05 18:03:11 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	execute_thread(t_ph *ph)
{
	pthread_mutex_lock(&ph->mutex[ph->index]);
	pthread_mutex_unlock(&ph->mutex[ph->index]);
	if (ph->index % 2 == 0)
	{
		print_status(THINK, ph, 0);
		usleep(800);
	}
	while (*(ph->tm_start) != 0)
	{
		take_fork_eat(ph);
		sleep_ph(ph);
		print_status(THINK, ph, 0);
	}
}

void	*th_start(void *tmp)
{
	t_ph			*ph;
	pthread_t		th;

	pthread_create(&th, NULL, checker, tmp);
	ph = (t_ph *)tmp;
	execute_thread(ph);
	pthread_join(th, NULL);
	pthread_exit(NULL);
}

void	unlock_thread(pthread_mutex_t *mutex, int i)
{
	while (i--)
		pthread_mutex_unlock(&mutex[i]);
}

unsigned long	*loop_mutex(pthread_mutex_t *mutex, unsigned long *ts)
{
	pthread_mutex_init(mutex, NULL);
	pthread_mutex_lock(mutex);
	return (ts);
}

void	create_thread(t_info info, int i, unsigned long ts)
{
	pthread_t		*th;
	t_ph			**ph;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	stick;
	int				*meal;

	ph = malloc(sizeof(t_ph *) * info.nb_philo);
	alloc_2(&mutex, &meal, &th, info);
	init_stick(&stick, meal == NULL, ph);
	while (i < info.nb_philo)
	{
		ph[i] = fully_ph(info, mutex, &stick, meal);
		ph[i]->tm_start = loop_mutex(&mutex[i], &ts);
		pthread_create(&th[i], NULL, th_start, (void *)ph[i]);
		i++;
	}
	ts = start_go();
	unlock_thread(mutex, i);
	loop_isf(info, &ts, meal);
	while (i--)
	{
		pthread_join(th[i], NULL);
		free_struct(ph[i]);
	}
	free2(mutex, meal, th, ph);
}
