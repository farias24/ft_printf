/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farias <farias@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:34:31 by farias            #+#    #+#             */
/*   Updated: 2024/10/15 16:34:38 by farias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_search_pointer(ptr / 16);
		ft_search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		size += ft_putstr("(nil)");
	else
	{
		size += ft_putstr("0x");
		ft_search_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}
