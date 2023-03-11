/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 22:06:12 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printer/printer.h"
#include "parser.h"

// Process a conversion specification in format string. A conversion spec is :
// %[flag][,flag...][field width][precision][length]conversion_specifier

// It's way too long, and not very clean...
// process_specification is a more exact name.
// char *specifier should be replaced by char *specification
int	process_specifier(char *specifier, va_list *args, int *ccount_p)
{
	int	i;
	int	proc;

	i = -1;
	proc = 0;
	// Where to implement the binary number or structure to know what
	// flag and option is active or not?
	while (specifier[++i]) // while processed && specifier[++i]. 
	// Or use if(processed) at the end of the loop.
	{
		// Why not try to split the process into two?
		// -> A function "process flags" that modifies the structure or binary
		// that tell other components what flags or options are open...
		// this function should return the offset for i to be placed on the
		// conversion specifier
		// -> A function "process specifier" that determine what to do with
		// the flag information according to the specifier
		if (specifier[i] == 'd' || specifier[i] == 'i')
			proc = putnbr_base_cctr(va_arg(*args, int),
					"0123456789", ccount_p);
			// proc could be an element of a strct that can be read every loop
			// this element could be a part of the same struct that manages
			// flags
		else if (specifier[i] == 'u')
			proc = putnbr_base_cctr(va_arg(*args, unsigned int),
					"0123456789", ccount_p);
		else if (specifier[i] == 'c')
			proc = putchar_cctr(va_arg(*args, int), ccount_p);
		else if (specifier[i] == '%' && specifier[i + 1] == '%')
		{
			proc = putchar_cctr('%', ccount_p);
			i++;
		}
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
		if (proc)
			break ;
	}
	return (i);
}
