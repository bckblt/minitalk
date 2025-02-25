#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
            ft_printf("\nMessage received from PID: %d\n", info->si_pid);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
    struct  sigaction   act;

    act.sa_sigaction = handle_signal;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);

    if((sigaction(SIGUSR1, &act, NULL) == -1) || (sigaction(SIGUSR2, &act, NULL) == -1))
        ft_printf("Error!");

    ft_printf("PID: %d\n", getpid());
    while (1)
        pause();

    return 0;
}
