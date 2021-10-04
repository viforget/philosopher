/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:24 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:06:26 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Error Value : 
** 1: Bad arg
** 2: Bad number of arg
*/

int	print_error(int value)
{
	if (value == 1)
		printf("Error : Bad Argument\n");
	else if (value == 2)
		printf("Error : Number of arguments must be between 4 and 5\n");
	exit (1);
}
