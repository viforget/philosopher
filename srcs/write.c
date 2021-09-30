#include "philo.h"

void	print_status(int time, int p, char *str, t_ph *ph)
{
	char	*tm;
	char	*phi;
	char	*tmp;
	char	*tmp2;
	
	if (*(ph->tm_start))
	{
		tm = ft_itoa(time);
		phi = ft_itoa(p);
		tmp = ft_strjoin(tm, " ");
		free(tm);
		tmp2 = ft_strjoin(tmp, phi);
		free(tmp);
		free(phi);
		tmp = ft_strjoin(tmp2, str);
		free(tmp2);
		pthread_mutex_lock(ph->talking_stick);
		if (*(ph->tm_start))
			write(1, tmp, ft_strlen(tmp));
		if (!ft_strcmp(str, DEAD))
			*(ph->tm_start) = 0;
		pthread_mutex_unlock(ph->talking_stick);
		free(tmp);
	}
}