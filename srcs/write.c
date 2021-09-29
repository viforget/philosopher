#include "philo.h"

void	print_status(int time, int ph, char *str, unsigned long *c)
{
	char	*tm;
	char	*phi;
	char	*tmp;
	char	*tmp2;
	
	if (*c)
	{
		tm = ft_itoa(time);
		phi = ft_itoa(ph);
		tmp = ft_strjoin(tm, " ");
		free(tm);
		tmp2 = ft_strjoin(tmp, phi);
		free(tmp);
		free(phi);
		tmp = ft_strjoin(tmp2, str);
		free(tmp2);
		if (*c)
			write(1, tmp, ft_strlen(tmp));
		free(tmp);
	}
}