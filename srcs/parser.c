#include "philo.h"

int	is_num(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

t_info	set_info()
{
	t_info	info;

	info.nb_philo = -1;
	info.tm_die = -1;
	info.tm_eat = -1;
	info.tm_slp = -1;
	info.nb_eat = -1;
	return (info);
}

t_info	parser(int ac, char **av)
{
	t_info	info;

	info = set_info();
	if (ac == 5 || ac == 6)
	{
		if (is_num(av[0]))
			info.nb_philo = ft_atoi(av[0]);
		if (is_num(av[1]))
			info.tm_die = ft_atoi(av[1]);
		if (is_num(av[2]))
			info.tm_eat = ft_atoi(av[2]);
		if (is_num(av[3]))
			info.tm_slp = ft_atoi(av[3]);
		if (ac == 6 && is_num(av[4]))
			info.nb_eat = ft_atoi(av[4]);
		else if (ac == 6)
			info.nb_eat = -2;
	}
	return (info);
}
