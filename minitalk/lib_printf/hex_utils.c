/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:45:54 by mfabbric          #+#    #+#             */
/*   Updated: 2023/02/03 16:25:01 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_putnbr(unsigned int n, char *hex)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_hex_putnbr(n / 16, hex);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_hex_pt_putnbr(unsigned long n, char *hex)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_hex_pt_putnbr(n / 16, hex);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_pt_putnbr(unsigned long n, char *hex)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_hex_pt_putnbr(n, hex);
	return (len);
}
