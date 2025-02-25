#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	flg_handler(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
		g_flag = 1;
}

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

void message_sender(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int main(int argc, char *argv[])
{
	int pid;
	char *message;
	if (argc != 3)
	{
		ft_printf("Usage: %s <Server PID> <Message>\n", argv[0]);
		return (0);
	}

	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, flg_handler);
	message = argv[2];
	while (*message)
		message_sender(pid, *message++);
	message_sender(pid, '\0');
	return 0;
}
