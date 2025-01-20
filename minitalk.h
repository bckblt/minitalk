#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

void    handle_signal(int signal);
void    message_sender(int pid, char *str);
int     ft_atoi(char *str);
void    ft_newline(int pid);

#endif