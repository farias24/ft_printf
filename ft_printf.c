/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farias <farias@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:21:37 by farias            #+#    #+#             */
/*   Updated: 2024/10/03 14:51:19 by farias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_type(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		size += ft_putchar((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		size += ft_print_pointer((unsigned long long)va_arg(args, void *));
	else if (c == 'u')
		size += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		size += ft_print_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		cont;
	va_list	args;

	i = 0;
	cont = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cont += ft_type(str[i], args);
		}
		else
		{
			ft_putchar(str[i]);
			cont++;
		}
		i++;
	}
	va_end(args);
	return (cont);
}
