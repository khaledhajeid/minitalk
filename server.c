#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


void signal_handler(int signal)
{
    static int number_of_bits = 0;
    static unsigned char c = 0;

    // number_of_bits = 0;
    // c = 0;
    c = c << 1;
    if (signal == SIGUSR2)
        c = c | 1;
    number_of_bits++;

    if (number_of_bits == 8)
    {
        write(1, &c, 1);
        number_of_bits = 0;
        c = 0;
    }
}

int main()
{
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while(1)
        pause();
}