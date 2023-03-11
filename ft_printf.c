/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 19:31:24 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printer/printer.h"
#include "parser/parser.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ccount;
	va_list	args;

	i = -1;
	ccount = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i += process_specifier((char *)format + i, &args, &ccount);
		else
			putchar_cctr(format[i], &ccount);
	}
	va_end(args);
	return (ccount);
}
