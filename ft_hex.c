/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farias <farias@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:16:08 by farias            #+#    #+#             */
/*   Updated: 2024/10/09 18:16:14 by farias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_search_hexadecimal(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_search_hexadecimal(num / 16, word);
		ft_search_hexadecimal(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
		{
			if (word == 'x')
				ft_putchar(num - 10 + 'a');
			if (word == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_print_hexadecimal(unsigned int num, const char word)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		ft_search_hexadecimal(num, word);
	return (ft_length_hexadecimal(num));
}
