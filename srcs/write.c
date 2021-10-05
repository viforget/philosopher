/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:05:26 by viforget          #+#    #+#             */
/*   Updated: 2021/10/05 11:33:35 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	condition(int dead, t_ph *ph)
{
	if (dead == 1)
		*(ph->tm_start) = 0;
	else if (dead == 2)
		ph->meal[ph->index]++;
}

void	print_status(char *str, t_ph *ph, int dead)
{
	char	*tm;
	char	*phi;
	char	*tmp;
	char	*tmp2;

	if (*(ph->tm_start))
	{
		phi = ft_itoa(ph->index);
		tmp = ft_strjoin(" ", phi);
		free(phi);
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		pthread_mutex_lock(ph->talking_stick);
		tm = ft_itoa(time_to_mili() - *ph->tm_start);
		tmp = ft_strjoin(tm, tmp2);
		free(tmp2);
		free(tm);
		if (*(ph->tm_start))
			write(1, tmp, ft_strlen(tmp));
		condition(dead, ph);
		pthread_mutex_unlock(ph->talking_stick);
		free(tmp);
	}
}
