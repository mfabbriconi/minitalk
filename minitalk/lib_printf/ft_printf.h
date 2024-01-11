/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:04:23 by mfabbric          #+#    #+#             */
/*   Updated: 2023/02/03 16:15:29 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int n);
int	ft_putstr(const char *str);
int	ft_putchar(const char c);
int	get_specifier(const char *str, va_list *args);
int	router(va_list *args, char c);
int	ft_u_putnbr(unsigned int n);
int	ft_hex_putnbr(unsigned int n, char *hex);
int	ft_hex_pt_putnbr(unsigned long n, char *hex);
int	ft_pt_putnbr(unsigned long n, char *hex);

#endif