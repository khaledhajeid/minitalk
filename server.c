#include "minitalk.h"

void signal_handler(int signal, siginfo_t *info, void *context)
{
	static int number_of_bits;
	static unsigned char c;
	
	(void)context;
	c = c << 1;
	if (signal == SIGUSR2)
		c = c | 1;
	number_of_bits++;
	if (number_of_bits == 8)
	{
		if (c == '\0')
		{
			write (1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		number_of_bits = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	struct sigaction s;

	s.sa_sigaction = signal_handler;
	s.sa_flags = SA_SIGINFO;

	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);

	while(1)
		pause();
}
