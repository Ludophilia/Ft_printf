/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:13 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/28 17:48:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.

// empty str
// stand str, without % specifier
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			++count;
		}
		// va_args(args, type);
	}
	va_end(args);
	return (count);
}
