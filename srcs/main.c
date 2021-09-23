#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (print_error(2));
	info = parser(ac, av + 1);
	if (!check_parsing(info))
		return (print_error(1));
	create_thread(info);
	return (0);
}
