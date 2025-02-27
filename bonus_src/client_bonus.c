/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:18:09 by bakarabu          #+#    #+#             */
/*   Updated: 2025/02/27 21:20:04 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_flag = 0;

void	flg_handler(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res);
}

void	message_sender(int pid, char c)
{
	int	bit;
	int	err;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (err == -1)
		{
			ft_printf("Wrong PID: %d", pid);
			exit (1);
		}
		while (!g_flag)
			;
		g_flag = 0;
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	char		*message;
	long long	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <Server PID> <Message>\n", argv[0]);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, flg_handler);
	message = argv[2];
	if (pid != 0)
	{
		while (*message)
			message_sender(pid, *message++);
	}
	if (pid != 0)
		message_sender(pid, '\0');
	return (0);
}
