/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:31:42 by kal-haj-          #+#    #+#             */
/*   Updated: 2025/09/23 13:31:44 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*append_char(char *message, char c, int *i)
{
	char	*new_msg;

	new_msg = malloc(*i + 2);
	if (!new_msg)
	{
		free(message);
		exit(1);
	}
	if (message)
	{
		ft_memcpy(new_msg, message, *i);
		free(message);
	}
	new_msg[*i] = c;
	new_msg[*i + 1] = '\0';
	(*i)++;
	return (new_msg);
}

static void	end_message(char **message, int *i, pid_t pid)
{
	if (*message)
	{
		ft_printf("%s\n", *message);
		free(*message);
		*message = NULL;
		*i = 0;
	}
	kill(pid, SIGUSR2);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				number_of_bits;
	static unsigned char	c;
	static char				*message;
	static int				i;

	(void)context;
	c = (c << 1) | (signal == SIGUSR2);
	number_of_bits++;
	if (number_of_bits == 8)
	{
		if (c == '\0')
			end_message(&message, &i, info->si_pid);
		else
			message = append_char(message, c, &i);
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
