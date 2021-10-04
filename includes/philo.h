/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:08:10 by viforget          #+#    #+#             */
/*   Updated: 2021/10/04 22:21:40 by viforget         ###   ########.fr       */
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

void			create_thread(t_info info, int i, unsigned long ts);

/*
** TIMER.C
/*/

unsigned long	time_to_mili(void);

/*
** EAT_SLEEP_THINK.C
*/

void			is_full(t_ph *ph);
void			take_fork_eat(t_ph *ph);
void			sleep_ph(t_ph *ph);

/*
** WRITE.C
*/

void			print_status(char *str, t_ph *ph, int dead);

/*
** SECOND_THREAD.C
*/

void			*checker(void *tmp);

/*
** ALLOC_FREE.C
*/

void			free_struct(t_ph *ph);
void			alloc_2(pthread_mutex_t **m, int **meal, pthread_t **th,
					t_info info);
void			free2(pthread_mutex_t *mutex, int *meal, pthread_t *th,
					t_ph **ph);
void			init_var(int *i, unsigned long *ts);
t_ph			*fully_ph(t_info info, pthread_mutex_t *m,
					pthread_mutex_t *st, int *ml);

#endif