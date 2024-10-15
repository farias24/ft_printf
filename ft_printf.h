/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farias <farias@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:22:14 by farias            #+#    #+#             */
/*   Updated: 2024/10/15 18:22:18 by farias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *str);
int	ft_print_hexadecimal(unsigned int num, const char word);
int	ft_type(char c, va_list args);
int	ft_print_pointer(unsigned long long ptr);
int	ft_printf(char const *str, ...);

#endif
