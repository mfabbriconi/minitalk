/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:43:17 by mfabbric          #+#    #+#             */
/*   Updated: 2023/09/12 15:35:36 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int segno, siginfo_t *info, void *context)
{
	static int	value;
	static int	bit_counter;

	(void)context;
	if (segno == SIGUSR1)
		value += 1 << bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &value, 1);
		if (value == '\0')
			kill(info->si_pid, SIGUSR1);
		value = 0;
		bit_counter = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	ft_printf("Starting server...\n");
	pid = getpid();
	ft_printf("PID:%d\n", pid);
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	while (1)
		pause();
}
