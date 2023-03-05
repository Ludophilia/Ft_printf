/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:28:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/04 14:03:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// How should this function work ? Any idea...?
int	ft_printf(const char *format, ...)
{
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

	// We will start by a simple case, just to start build the skills to
	// write this program:
		// one int argument, %i/%d. From an int (42).

	int	i;
	
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i += process_specifier(format + i); // returns the offset to 
			// skip to the part outside %*}
		else
			ft_putchar_fd(format[i], 1); // kind of inefficient
	}
	// ft_putstr_fd((char *)format, 1);
	return (0);  // what should be returned?
}
