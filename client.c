#include "minitalk.h"

int ack_receive = 0;

void ack(int sig)
{
	if (sig == SIGUSR1)
		ack_receive = 1;
	else if (sig == SIGUSR2)
		exit(0);
}

void send_bits(int PID, unsigned char c)
{
	int i;

	i = 7;
	while (i >= 0) 
	{
		ack_receive = 0;
		if ((c >> i) & 1)
			kill(PID, SIGUSR2);
		else
			kill(PID, SIGUSR1);
		usleep(300);
		while (ack_receive != 1)
			pause();
		i--;
	}
}

int main(int argc, char *argv[])
{
	int PID;
	unsigned char *message;
	int i;

	i = 0;
    	if (argc != 3)
		return (1);
	PID = ft_atoi(argv[1]);
	message = (unsigned char *)argv[2];
	signal(SIGUSR1, ack);
	signal(SIGUSR2, ack);
	while (message[i])
	{
		send_bits(PID, message[i]);
		i++;
	}
	send_bits(PID, '\0');
	while (1)
		pause();
	return (0);
}
