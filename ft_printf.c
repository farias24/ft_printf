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
#include "libftprint.h"

int	ft_type(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 's')
		size += ft_putstr((char *)va_arg(args, int *));
	else if (c == 'c')
		size += ft_putchar((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		size += ft_printpointer(va_arg(args, int));
	else if (c == 'u')
	else if (c == 'x')
    else if (c == 'X')
    else if (c == '%')
		ft_putchar('%');
	return (size)
}

int	ft_printf(char const *str, ...)
{
	int	i;
	int 	cont;
	va_list	args;

	i = 0;
	cont = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cont += ft_type(str[i++]);
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
