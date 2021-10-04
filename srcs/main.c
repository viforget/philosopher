/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:44 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:19:53 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (print_error(2));
	info = parser(ac, av + 1);
	if (!check_parsing(info))
		return (print_error(1));
	if (info.nb_philo != 1)
		create_thread(info, 0, 0);
	else
		printf("0 0 is thinking\n0 0 as taken a fork\n%d 0 is dead\n",
			info.tm_die);
	return (0);
}
