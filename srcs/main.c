/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:44 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:06:45 by viforget         ###   ########.fr       */
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
	create_thread(info, 0, 0);
	return (0);
}
