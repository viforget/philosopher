/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:21:34 by viforget          #+#    #+#             */
/*   Updated: 2021/10/01 14:21:48 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *tmp)
{
	t_ph			*ph;

	ph = (t_ph *)tmp;
	while (!*(ph->tm_start))
		;
	*(ph->tm_lst_eat) = time_to_mili();
	while (*(ph->tm_start))
	{
		if (*(ph->tm_lst_eat) + ph->info.tm_die < time_to_mili())
		{
			print_status(time_to_mili() - *ph->tm_start, ph->index, DEAD, ph);
			*(ph->tm_start) = 0;
		}
	}
	pthread_exit(NULL);
}
