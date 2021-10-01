/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:08:10 by viforget          #+#    #+#             */
/*   Updated: 2021/10/01 14:08:12 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# include "../libft/libft.h"

# define FORK " as taken a fork\n"
# define EAT " is eating\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define DEAD " is dead\n"

typedef struct s_info
{
	int			nb_philo;
	int			tm_die;
	int			tm_eat;
	int			tm_slp;
	int			nb_eat;
}				t_info;

typedef struct s_ph
{
	int						index;
	t_info					info;
	char					*is_dead;
	unsigned long			*tm_start;
	unsigned long			*tm_lst_eat;
	pthread_mutex_t			*mutex;
	pthread_mutex_t			*talking_stick;
	int						*meal;
}							t_ph;

/*
** PARSER.C
*/

t_info			parser(int ac, char **av);

/*
** CHECK_PARSING.C
*/

int				check_parsing(t_info info);

/*
** ERROR.C
*/

int				print_error(int value);

/*
** CREATE_THREAD.C
*/

void			create_thread(t_info info);

/*
** TIMER.C
/*/

unsigned long	time_to_mili(void);

/*
** EAT_SLEEP_THINK.C
*/

int				take_fork_eat(t_ph *ph);
int				sleep_ph(t_ph *ph);

/*
** WRITE.C
*/

void			print_status(int time, int p, char *str, t_ph *ph);

/*
** SECOND_THREAD.C
*/

void			*checker(void *tmp);

#endif