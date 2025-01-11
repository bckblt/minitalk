#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_signal(int signal)
{
    static int bit = 7;
    static int set = 0;
    
    if (signal == SIGUSR1)
        set += (1 << bit);

    if (bit == 0)
    {
        printf("%c", set);
        bit = 7;
        set = 0;
    }
    else
        bit--;
}

int main()
{
    printf("Server PID: %d\n", getpid());

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1)
        pause();

    return 0;
}
