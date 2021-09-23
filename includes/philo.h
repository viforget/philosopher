#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# include "../libft/libft.h"

typedef struct s_info
{
	int			nb_philo;
	int			tm_die;
	int			tm_eat;
	int			tm_slp;
	int			nb_eat;
}				t_info;

typedef struct 				s_ph
{
	int						index;
	t_info					info;
	char					*is_dead;
	unsigned long			*tm_start;
	unsigned long			*tm_lst_eat;
	pthread_mutex_t 		*mutex;
}							t_ph;

/*
** PARSER.C
*/

t_info	parser(int ac, char **av);

/*
** CHECK_PARSING.C
*/

int		check_parsing(t_info info);

/*
** ERROR.C
*/

int		print_error(int value);

/*
** CREATE_THREAD.C
*/

void	create_thread(t_info info);

/*
** TIMER.C
/*/

unsigned long	time_to_mili();

/*
** EAT_SLEEP_THINK.C
*/

void	take_fork_eat(t_ph *ph);
int		sleep_ph(t_ph *ph);

#endif