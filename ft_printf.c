/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 15:09:40 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printer/printer.h"
#include "parser/parser.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;
	int ccount;
	
	va_start(args, format);
	i = -1;
	ccount = 0;
	while (format[++i])
	{
		// printf("\t[DB]i = %i, format[i] = '%c'\n", i, format[i]);
		if (format[i] == '%')
		{
			// printf("\t[DB]i before process_specifier: %i\n", i);
			i += process_specifier((char *)format + i, &args, &ccount);
			// printf("\t[DB]i after process_specifier: %i\n\n", i);
		}
		else
			putchar_cctr(format[i], &ccount); // kind of inefficient
	}
	// printf("\t[DB]i = %i, i = '%c'\n", i, format[i]);
	va_end(args);
	return (ccount);
}
