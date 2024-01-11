/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:30 by mfabbric          #+#    #+#             */
/*   Updated: 2023/02/03 16:36:34 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		len += write(1, (char *)&str[i++], 1);
	return (len);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int		temp;
	int		len;

	len = 0;
	if (n == -2147483648)
		len += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			len += ft_putchar('-');
		}
		if (n <= 9)
			len += ft_putchar(n + 48);
		else
		{
			temp = (n % 10) + '0';
			n = n / 10;
			len += ft_putnbr(n);
			len += write(1, (char *)&temp, 1);
		}
	}
	return (len);
}

int	ft_u_putnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_u_putnbr(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}
