/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:21:34 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 20:31:27 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *tmp)
{
	t_ph	*ph;
	int		die;		

	ph = (t_ph *)tmp;
	die = ph->info.tm_die;
	while (!*(ph->tm_start))
		;
	*(ph->tm_lst_eat) = time_to_mili();
	while (*(ph->tm_start))
	{
		if ((*(ph->tm_lst_eat) + die) - time_to_mili() < 0)
		{
			print_status(DEAD, ph, 1);
			*(ph->tm_start) = 0;
		}
		is_full(ph);
	}
	pthread_exit(NULL);
}
