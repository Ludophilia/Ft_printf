/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:24:27 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/04 14:07:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putchar_cc(char c, int *count)
{
	ft_putchar_fd(c, 1);
	*count += 1;
}

static void	putstr_cc(char *s, int *count)
{
	ft_putstr_fd(s, 1);
	*count += ft_strlen(s);
}

void	print_char(char c, int *count)
{
	putchar_cc(c, count);
}

void	print_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	putstr_cc(str, count);
}

void	print_nbr(t_nbr nb, char *base, t_flag *flags, int *count)
{
	unsigned long	radix;

	if (nb.abs == 0 && flags->conv_t == 'p')
		return (putstr_cc("(nil)", count));
	radix = ft_strlen(base);
	if (nb.abs >= radix)
		print_nbr((t_nbr){nb.sign, nb.abs / radix}, base, flags, count);
	if (nb.abs < radix && nb.sign)
		putchar_cc('-', count);
	else if (nb.abs < radix && flags->conv_t == 'p')
		putstr_cc("0x", count);
	putchar_cc(base[nb.abs % radix], count);
}
