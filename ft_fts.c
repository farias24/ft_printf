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

int	ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	nbr;

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
	i++;
	return (i);
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
	return (i)
}