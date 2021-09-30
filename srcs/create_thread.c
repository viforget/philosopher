#include "philo.h"

void	*th_start(void *tmp)
{
	t_ph	*ph;
	int 	a;

	a = 1;
	ph = (t_ph *)tmp;
	while (!*(ph->tm_start))
		;
	if (ph->index % 2 == 0)
	{
		print_status(time_to_mili() - *ph->tm_start, ph->index, THINK, ph);
		usleep(10);
	}
	while (a == 1 && *(ph->tm_start) != 0)
	{
		a = take_fork_eat(ph);
		if (a)
			a = sleep_ph(ph);
		if (a == 1 && *(ph->tm_start) != 0)
			print_status(time_to_mili() - *ph->tm_start, ph->index, THINK, ph);
		else
			*(ph->tm_start) = 0;
	}
	*(ph->tm_start) = 0;
	pthread_exit(NULL);
}

t_ph	*fully_ph(t_info info, char *id, int i, unsigned long *ts, pthread_mutex_t *mutex, pthread_mutex_t *stick, int *meal)
{
	t_ph			*ph;
	unsigned long	*a;
	int				j;

	j = 0;
	while (j < info.nb_philo)
		meal[j++] = 0;
	a = malloc(sizeof(unsigned long));
	ph = malloc(sizeof(t_ph));
	ph->index = i;
	ph->info = info;
	ph->is_dead = id;
	ph->tm_start = ts;
	ph->tm_lst_eat = a;
	ph->mutex = mutex;
	ph->talking_stick = stick;
	ph->meal = meal;
	return (ph);
}

void	create_thread(t_info info)
{
	pthread_t		th[info.nb_philo + 1];	//PENSER A LES MALLOC
	t_ph			*ph[info.nb_philo];		//PENSER A LES MALLOC
	pthread_mutex_t	*mutex;
	pthread_mutex_t	stick;
	int				i;
	char			id;
	unsigned long	ts;
	int				*meal;

	i = 0;
	id = 0;
	ts = 0;
	meal = malloc(sizeof(int) * info.nb_philo);
	mutex = malloc(sizeof(pthread_mutex_t) * info.nb_philo);
	pthread_mutex_init(&stick, NULL);
	while (i < info.nb_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		ph[i] = fully_ph(info, &id, i, &ts, mutex, &stick, meal);	
		pthread_create(&th[i + 1], NULL, th_start, (void *)ph[i]);
		i++;
	}
	usleep(1000);
	ts = time_to_mili();
	while (i--)
	{
		pthread_join(th[i + 1], NULL);
	}
}
