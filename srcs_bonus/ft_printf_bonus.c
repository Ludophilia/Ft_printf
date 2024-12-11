/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:13 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 15:37:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// FORMAT
// %[flags][width][precision]sp

// SPECIFIER (sp)
// c spdiuxX%

// ---------------------------

// -
// width

// 0 (d, i, u, x, X)
// # (x, X)
// + (d, i)
// space (d, i?)

// . (s, d, i, u, x, X)

// ---------------------------

// NEXT TESTS
// - Errors 
// - %c with - and width
// - 

int	ft_printf(const char *format, ...)
{
	t_meta	meta;
	int		i;

	if (format == NULL)
		return (-1);
	i = 0;
	meta = (t_meta){.i = &i, .count = 0, .flags = 0, .field_v = -1,
		.prec_v = -1};
	va_start(meta.args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid_specif(format + ++i, &meta))
			process_specifier(format + ++i, &meta);
		else
			ft_putchar_cc(format[i++], &meta);
	}
	va_end(meta.args);
	return (meta.count);
}
