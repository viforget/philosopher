#include "philo.h"

void	take_fork_eat(t_ph *ph)
{
	pthread_mutex_lock(&ph->mutex[ph->index]);
	print_status(time_to_mili() - *ph->tm_start, ph->index, FORK, ph->tm_start);
//	printf("%d as taken a fork\n", ph->index);
	pthread_mutex_lock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
	print_status(time_to_mili() - *ph->tm_start, ph->index, FORK, ph->tm_start);
//	printf("%d as taken a fork\n", ph->index);
	print_status(time_to_mili() - *ph->tm_start, ph->index, EAT, ph->tm_start);
//	printf("%d is eating\n", ph->index);
	*(ph->tm_lst_eat) = time_to_mili();
	usleep(ph->info.tm_eat * 1000);
	pthread_mutex_unlock(&ph->mutex[ph->index]);
	pthread_mutex_unlock(&ph->mutex[(ph->index + 1) % ph->info.nb_philo]);
}

int	sleep_ph(t_ph *ph)
{
	unsigned long	time;

	time = time_to_mili();
	if (*(ph->tm_start) != 0)
	print_status(time_to_mili() - *ph->tm_start, ph->index, SLEEP, ph->tm_start);
	//printf("%d is sleeping\n", ph->index);
	if (time + ph->info.tm_slp > *(ph->tm_lst_eat) + ph->info.tm_die)
	{
		usleep((*(ph->tm_lst_eat) + ph->info.tm_die - time) * 1000);
		if (*(ph->tm_start) != 0)
			print_status(time_to_mili() - *ph->tm_start, ph->index, DEAD, ph->tm_start);
		//printf("%d is dead\n", ph->index);
		*(ph->tm_start) = 0;
		return (0);
	}
	usleep(ph->info.tm_slp * 1000);
	return (1);
}