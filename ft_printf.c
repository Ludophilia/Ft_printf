/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 21:42:56 by jgermany         ###   ########.fr       */
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
	// How to manage flags?
	// 	- It's still a matter of parsing the str:
	//		- % still triggers the parsing
	//		- '-' '+' ' ' '#' '0'... modifies the behavior of the putchar,
	//		putstr, putnbr functions used for display. Writing wrappers
	//		around those functions was really NOT a bad idea!
	//			- We have to understand how to improve those wrappers then
	//			and how to trigger them
	//			- Certainely via a pointer to a binary num or a structure that
	//			will be defined in process_specifier (parser level)
	//			as every specification has its own set of flags
	//		- 'd' 'u' 'p'... still triggers the consumption of one element of
	//		va_list, its conversion, and its printing on stdout. Obviously,
	//		this time, the printing is influenced 
	//  
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
