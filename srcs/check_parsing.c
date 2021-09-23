#include "philo.h"

int	check_parsing(t_info info)
{
	if (info.nb_philo == -1 || info.tm_die == -1
		|| info.tm_eat == -1 || info.tm_slp == -1
		|| info.nb_eat == -2)
		return (0);
	return (1);
}
