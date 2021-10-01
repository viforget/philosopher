#include "philo.h"

void	*checker(void *tmp)
{
	t_ph			*ph;

	ph = (t_ph *)tmp;
	while(*(ph->tm_start))
	{
		if (*(ph->tm_lst_eat) + ph->info.tm_die < time_to_mili())
		{
			print_status(time_to_mili(), ph->index, DEAD, ph);
		}
	}
	pthread_exit(NULL);
}