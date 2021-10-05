/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:21:26 by viforget          #+#    #+#             */
/*   Updated: 2021/10/05 11:29:57 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_full(t_info info, unsigned long *ts, int *meal)
{
	int	i;
	int	ch;

	i = 0;
	ch = 0;
	if (info.nb_eat != -1 && *(ts) != 0)
	{
		while (ch == 0 && i < info.nb_philo)
		{
			if (meal[i] < info.nb_eat)
				ch = 1;
			i++;
		}
		if (ch == 0)
			*(ts) = 0;
	}
}

void	loop_isf(t_info info, unsigned long *ts, int *meal)
{
	while (*ts)
		is_full(info, ts, meal);
}

void	take_fork_eat(t_ph *ph)
{
	pthread_mutex_lock(&ph->mutex[ph->index]);
	print_status(FORK, ph, 0);
	pthread_mutex_lock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
	print_status(FORK, ph, 0);
	*(ph->tm_lst_eat) = time_to_mili();
	print_status(EAT, ph, 2);
	*(ph->tm_lst_eat) = time_to_mili();
	if (ph->info.tm_die < ph->info.tm_eat)
	{
		usleep(ph->info.tm_die * 1000);
		print_status(DEAD, ph, 1);
		*(ph->tm_start) = 0;
	}
	else
	{
		usleep(ph->info.tm_eat * 1000);
	}
	pthread_mutex_unlock(&ph->mutex[ph->index]);
	pthread_mutex_unlock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
}

void	sleep_ph(t_ph *ph)
{
	unsigned long	time;

	time = time_to_mili();
	print_status(SLEEP, ph, 0);
	usleep(ph->info.tm_slp * 1000);
}
