/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:38 by mfabbric          #+#    #+#             */
/*   Updated: 2023/09/12 15:19:59 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(char c, int bit_count, int pid)
{
	while (bit_count < 8)
	{
		if ((c & (1 << bit_count)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_count++;
		usleep(1200);
	}
}

void	ft_check_bit(int pid, char *s)
{
	int		i;
	int		bit_count;

	i = 0;
	while (s[i])
	{
		bit_count = 0;
		ft_send(s[i], bit_count, pid);
		i++;
	}
}

void	ft_hand_signal(int i)
{
	(void)i;
	ft_printf("message sent to the server\n");
}

int	main(int argc, char **argv)
{
	pid_t	c;

	c = 0;
	if (argc != 3)
	{
		ft_printf("Client Error\n");
		ft_printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", argv[0]);
		exit(0);
	}
	c = ft_atoi(argv[1]);
	signal(SIGUSR1, &ft_hand_signal);
	ft_check_bit(c, argv[2]);
	ft_send('\n', 0, c);
	ft_send('\0', 0, c);
}
