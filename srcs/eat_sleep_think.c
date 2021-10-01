/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:21:26 by viforget          #+#    #+#             */
/*   Updated: 2021/10/01 14:21:28 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_full(t_ph *ph)
{
	int	i;
	int	ch;

	i = 0;
	ch = 0;
	if (ph->info.nb_eat != -1 && *(ph->tm_lst_eat) != 0)
	{
		ph->meal[ph->index]++;
		while (ch == 0 && i < ph->info.nb_philo)
		{
			if (ph->meal[i] < ph->info.nb_eat)
				ch = 1;
			i++;
		}
		if (ch == 0)
			*(ph->tm_start) = 0;
	}
}

int	take_fork_eat(t_ph *ph)
{
	pthread_mutex_lock(&ph->mutex[ph->index]);
	print_status(time_to_mili() - *ph->tm_start, ph->index, FORK, ph);
	pthread_mutex_lock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
	print_status(time_to_mili() - *ph->tm_start, ph->index, FORK, ph);
	*(ph->tm_lst_eat) = time_to_mili();
	if (ph->info.tm_die < ph->info.tm_eat)
	{
		usleep(ph->info.tm_die * 1000);
		print_status(time_to_mili() - *ph->tm_start, ph->index, DEAD, ph);
		*(ph->tm_start) = 0;
	}
	else
	{
		print_status(time_to_mili() - *ph->tm_start, ph->index, EAT, ph);
		is_full(ph);
		usleep(ph->info.tm_eat * 1000);
	}
	pthread_mutex_unlock(&ph->mutex[ph->index]);
	pthread_mutex_unlock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
	return (*(ph->tm_start) != 0);
}

int	sleep_ph(t_ph *ph)
{
	unsigned long	time;

	time = time_to_mili();
	if (*(ph->tm_start) != 0)
		print_status(time_to_mili() - *ph->tm_start, ph->index, SLEEP, ph);
	if (time + ph->info.tm_slp > *(ph->tm_lst_eat) + ph->info.tm_die)
	{
		usleep((*(ph->tm_lst_eat) + ph->info.tm_die - time) * 1000);
		if (*(ph->tm_start) != 0)
			print_status(time_to_mili() - *ph->tm_start, ph->index, DEAD, ph);
		*(ph->tm_start) = 0;
		return (0);
	}
	usleep(ph->info.tm_slp * 1000);
	return (1);
}
