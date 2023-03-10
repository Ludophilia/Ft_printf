/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 00:23:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// How should this function work ? Any idea...?
// Everything starts with the format string. The format string should 
// be parsed:

	// * Iterate on every char of format str
		// * Every 'normal' character will be printed on stdout 
		// * When '%' sign is encountered:
			// * Build the logic to map the following characters to 
			// 	a conversion. In any case, the logic is complete if a
			// 	i,d,p,x,X,c,s,u is encountered.
			// * Determine the conversion to use
			// * convert the associated argument
			// * print it on stdout.
			// * No formatting for now.
int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;
	unsigned int prtd;
	
	va_start(args, format);
	i = -1;
	prtd = 0;
	while (format[++i])
	{
		// printf("\t[DB]i = %i, format[i] = '%c'\n", i, format[i]);
		if (format[i] == '%')
		{
			// printf("\t[DB]i before process_specifier: %i\n", i);
			i += process_specifier((char *)format + i, &args);
			// printf("\t[DB]i after process_specifier: %i\n\n", i);
		}
		else
			ft_putchar_fd(format[i], 1); // kind of inefficient
	}
	// printf("\t[DB]i = %i, i = '%c'\n", i, format[i]);
	va_end(args);
	return (prtd); // returns the number of characters printed on stdout as an int 
}
