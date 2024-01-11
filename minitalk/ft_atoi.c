/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:19:16 by mfabbric          #+#    #+#             */
/*   Updated: 2023/09/20 15:19:45 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			n;
	int			sign;
	const char	*s;

	n = 0;
	sign = 1;
	s = str;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'
		|| *s == '\f' || *s == '\v')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10;
		n += *s - '0';
		s++;
	}
	return (n * sign);
}
