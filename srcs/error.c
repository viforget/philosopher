#include "philo.h"

/*
** Error Value : 
** 1: Bad arg
** 2: Bad number of arg
*/

int	print_error(int value)
{
	if (value == 1)
		printf("Error : Bad Argument\n");
	else if (value == 2)
		printf("Error : Number of arguments must be between 4 and 5\n");
	exit (1);
}
