#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void send_bits(int PID, char c)
{
	int i;

	i = 7;
	while (i >= 0) 
	{
		if ((c >> i) & 1)
			kill(PID, SIGUSR2);
		else
			kill(PID, SIGUSR1);
		usleep(100);
		//printf("%d\n", (c >> i));
		i--;
	}
}

int main(int argc, char *argv[])
{
	int PID;
	char *message;
	int i;

	i = 0;
    	if (argc != 3)
		return (1);

	PID = atoi(argv[1]);
	message = argv[2];
	
	while (message[i])
	{
		send_bits(PID, message[i]);
		i++;
	}
	return (0);
}

