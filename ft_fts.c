/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farias <farias@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:08:32 by farias            #+#    #+#             */
/*   Updated: 2024/10/03 15:08:34 by farias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int				i;
	unsigned long long	nbr;

	i = 0;
	if (nb < 0)
	{
		ft_putchar ('-');
		nbr = -nb;
		i++;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	i += ft_putchar(nbr % 10 + 48);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_putchar('0');
	else
	{
		if (n / 10 != 0)
			ft_putnbr_unsigned(n / 10);
		ft_putchar((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
