#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void message_sender(int pid, char *str)
{
    int bit;
    int j;
    int i;
    char c;

    i = 0;
    while (str[i])
    {
        c = str[i];
        j = 7;
        while (j >= 0)
        {
            bit = (c >> j) & 1;
            if(bit)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);

            usleep(100);
                j--;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    char *message;
    if (argc != 3)
    {
        printf("Usage: %s <Server PID> <Message>\n", argv[0]);
        return (0);
    }

    pid = atoi(argv[1]);
    message = argv[2];

    message_sender(pid, message);

    return 0;
}
