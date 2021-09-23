#include "philo.h"

unsigned long	time_to_mili()
{
	struct timeval	tm;
	
	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}