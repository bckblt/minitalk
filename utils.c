#include "minitalk.h"

int ft_atoi(char *str)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res);
}


void ft_newline(int pid)
{
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
}