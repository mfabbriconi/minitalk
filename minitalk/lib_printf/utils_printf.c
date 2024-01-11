/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:49:11 by mfabbric          #+#    #+#             */
/*   Updated: 2023/02/03 16:40:04 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_specifier(const char *str, va_list *args)
{
	int		j;
	int		i;
	int		len;

	i = -1;
	j = 0;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			len += router(args, str[i]);
			j++;
		}
		else
			len += write(1, (char *)&str[i], 1);
	}
	return (len);
}

int	router(va_list *args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'p' || c == 'P')
		len += ft_pt_putnbr(va_arg(*args, unsigned long), "0123456789abcdef");
	else if (c == 'd')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		len += ft_u_putnbr(va_arg(*args, unsigned int));
	else if (c == 'x')
		len += ft_hex_putnbr(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_hex_putnbr(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}
