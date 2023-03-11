/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 20:23:27 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printer/printer.h"
#include "parser.h"

// It's way too long, and not very clean...
int	process_specifier(char *specifier, va_list *args, int *ccount_p)
{
	int	i;
	int	proc;

	i = -1;
	proc = 0;
	while (specifier[++i])
	{
		if (specifier[i] == 'd' || specifier[i] == 'i')
			proc = putnbr_base_cctr(va_arg(*args, int),
					"0123456789", ccount_p);
		else if (specifier[i] == 'c')
			proc = putchar_cctr(va_arg(*args, int), ccount_p);
		else if (specifier[i] == 'u')
			proc = putnbr_base_cctr(va_arg(*args, unsigned int),
					"0123456789", ccount_p);
		else if (specifier[i] == 's')
			proc = putstr_cctr(va_arg(*args, char *), ccount_p);
		else if (specifier[i] == 'x')
			proc = putnbr_base_cctr(va_arg(*args, unsigned int),
					"0123456789abcdef", ccount_p);
		else if (specifier[i] == 'X')
			proc = putnbr_base_cctr(va_arg(*args, unsigned int),
					"0123456789ABCDEF", ccount_p);
		else if (specifier[i] == 'p')
		{
			proc = putstr_cctr("0x", ccount_p);
			proc = putnbr_base_cctr(va_arg(*args, uintptr_t),
					"0123456789abcdef", ccount_p);
		}
		else if (specifier[i] == '%' && specifier[i + 1] == '%')
		{
			proc = putchar_cctr('%', ccount_p);
			i++;
		}
		if (proc)
			break ;
	}
	return (i);
}
