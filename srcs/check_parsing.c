/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:58 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:06:59 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_parsing(t_info info)
{
	if (info.nb_philo == -1 || info.tm_die == -1
		|| info.tm_eat == -1 || info.tm_slp == -1
		|| info.nb_eat == -2)
		return (0);
	return (1);
}
