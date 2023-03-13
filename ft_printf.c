/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/13 17:27:22 by jgermany         ###   ########.fr       */
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
	//			will be defined in process_specification (parser level)
	//			as every specification has its own set of flags...
	
	//		- 'd' 'u' 'p'... still triggers the consumptio n of one element of
	//		va_list, its conversion, and its printing on stdout. Obviously,
	//		this time, the printing is influenced by the flags and over options
	//		...
	//  
	while (format[++i])
	{
		if (format[i] == '%') // if the % spec does not work? Why not do:
			// if (format[i] == '%' && proc_specif) ? If proc_specif returns 0
			// that means that it should be ignored 
			i += proc_specif((char *)format + i + 1, &args, &ccount);
		else
			putchar_cctr(format[i], &ccount);
	}
	va_end(args);
	return (ccount);
}
